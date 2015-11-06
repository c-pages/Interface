

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>
#include "GUI.h"

namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran             ( appli )
, m_gui             ( new gui::Groupe() )
{
   // m_gui = std::shared_ptr<gui::Groupe>  ( new gui::Groupe()  );
    // Initialisation de l'interface graphique.
    initGUI     ();
    initScene   ();

    // les vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre().getSize() );
    m_vueJeu.setSize(pos);
    m_vueGUI.setSize(pos);
    pos *= 0.5f;
    m_vueJeu.setCenter(pos);
    m_vueGUI.setCenter(pos);



}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...

    // Evenements de l'interface
    m_gui->traiter_evenements    ( event );



    if (event.type == sf::Event::Closed)
        m_appli->getFenetre().close();


    // Resize the window
    if (event.type ==  sf::Event::Resized)
    {
        m_vueJeu.setSize    (event.size.width, event.size.height);
        m_vueGUI.setSize    (event.size.width, event.size.height);

    m_appli->getFenetre().setView(m_vueGUI);

//          this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
//          this->game->background.setScale(
//          float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
//          float(event.size.height) / float(this->game->background.getTexture()->getSize().y));

    }


}



/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_gui->actualiser    ( deltaT );
}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    // Dessiner la fenetre du jeu

    // Dessiner l'interface
    m_appli->getFenetre().draw ( *m_gui);



    m_appli->getFenetre().setView   ( m_vueJeu);
    m_appli->getFenetre().draw      ( m_fond );

    m_appli->getFenetre().setView   ( m_vueGUI );
    m_appli->getFenetre().draw      ( *m_gui );




}


/////////////////////////////////////////////////
void
EcranDemo::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }


/////////////////////////////////////////////////
void
EcranDemo::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );
    m_fond.setFillColor ( sf::Color (40,40,50));
    m_gui->setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ()
{
    // initialisation des parametres du GUI, les icones, polices...
    gui::init();


    // le skin qu'on va utiliser dans cette interface
    auto skinCourant =  Config::m_skins[ Config::Skins::Skin1 ] ;


    // creation du log
    auto log = gui::Log::Instance();
    m_gui->ajouter          ( log );
    log->setSkin ( skinCourant );


    // creation du gadget Infos
    auto infos  = std::shared_ptr<gui::Infos>   ( new gui::Infos  (  skinCourant ) );
    m_gui->ajouter  ( infos );
    infos->setPosition ( m_appli->getFenetre().getSize().x - 170 , 0);


    // le champ de saisie
    m_champ = std::shared_ptr<gui::ChampTexte>   ( new gui::ChampTexte  (  { 150 , 20 } , skinCourant ) );
    m_champ->setPosition    ( { 10 , 10 });
    m_champ->setTexte       ( "Champ de saisie" );
    m_champ->lier           ( gui::Evenements::onCha_ChangeValeur , [this](){
        std::cout << "onCha_changeValeur\n";
        gui::Log::print (  "Texte saisie : " + m_champ->getTexte() );
    } );

//
//    // bouton
//    std::shared_ptr<gui::Bouton>  bouton ( new gui::Bouton  (  skinCourant ) );
//    bouton->setPosition ( { 170 , 35 });
//    bouton->setSize ( { 20 , 20 });
//    bouton->lier ( gui::Evenements::onBtnG_Relache , [this](){
//       // gui::Log::print (  "Texte : " + m_champ->getTexte() );
//    } );


    // BoutonFleche
    std::shared_ptr<gui::BoutonFleche>  boutonFleche  ( new gui::BoutonFleche  (   ) );
    boutonFleche->setPosition ( { 10 , 40 });
    boutonFleche->setVal ( 20.0 );
    boutonFleche->setSkin ( skinCourant );
    boutonFleche->setPrecision (1);





    // la fenetre
    std::shared_ptr<gui::Fenetre>  fenetre ( new gui::Fenetre   ( &m_appli->getFenetre()
                                                                , sf::Vector2f (270, 200) ) );
    m_gui->ajouter          ( fenetre );
    fenetre->setPosition    ( 150 , 150 );
    fenetre->setSkin        ( skinCourant );




    // ajouter à le fenetre
    fenetre->ajouter          ( m_champ );
  //  fenetre->ajouter          ( bouton );
    fenetre->ajouter          ( boutonFleche );
   // m_gui->ajouter          ( boutonFleche );


}   // fin init GUI




}   // fin namespace app































