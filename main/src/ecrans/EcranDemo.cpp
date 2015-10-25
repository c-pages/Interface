

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
: Ecran     ( appli )
, m_gui     (  )
{
    // Initialisation de l'interface graphique.
    initGUI     ();
    initScene   ();
}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...

    // Evenements de l'interface
    m_gui.traiter_evenements    ( event );
}


/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_gui.actualiser    ( deltaT );
}


/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    // Dessiner la fenetre du jeu
    m_appli->getFenetre().draw ( m_fond );

    // Dessiner l'interface
    m_appli->getFenetre().draw ( m_gui );
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
    m_fond.setFillColor ( sf::Color (50,50,50));
}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ( )
{
    // le skin qu'on va utiliser dans cette interface
    auto skinCourant =  Config::m_skins[ Config::Skins::Skin1 ] ;
//
//    // creation du label
//    this->m_lblTest = std::shared_ptr<gui::Label> ( new gui::Label ( "Ceci est un label : gui::Label" , skinCourant->lblCourant ) );
//    m_gui.ajouter ( m_lblTest );
//    m_lblTest->setPosition  ( 20,20);
//
//
//    // creation du Bouton simple A, c'est un shared_ptr de l'ecranDemo
//    std::shared_ptr<gui::BoutonTexte>  boutonA ( new gui::BoutonTexte ( skinCourant ) );
//    m_gui.ajouter           ( boutonA );
//    boutonA->setPosition    ( 20, 50 );
//    boutonA->lier           ( gui::Evenements::onGRelache , [this]() {
//        m_lblTest->setTexte( "Le plus simple des boutons : gui::Bouton");
//    });
//
//
//
//
//    // creation du BoutonTexte B, nouveau pointeur, ajouté aux enfants du groupe GUI principal.
//    std::shared_ptr<gui::BoutonTexte>  boutonB ( new gui::BoutonTexte ( skinCourant , "Bouton" ) );
//    m_gui.ajouter           ( boutonB );
//    boutonB->setPosition    ( 50, 50 );
//    boutonB->setBordure     ( 5 );
//    boutonB->ajusterAuTexte ( );
//    boutonB->lier           ( gui::Evenements::onGRelache , [this]() {
//        m_lblTest->setTexte( "Un bouton avec texte : gui::BoutonTexte");
//    });
//
//
//
//
//    // creation du BoutonTexte B, nouveau pointeur, ajouté aux enfants du groupe GUI principal.
//    std::shared_ptr<gui::BoutonCocher>  boutonC ( new gui::BoutonCocher ( skinCourant ) );
//    m_gui.ajouter           ( boutonC );
//    boutonC->setPosition    ( 50, 50 );
//    boutonC->setSize        ( { boutonB->getSize().y , boutonB->getSize().y } );
//    boutonC->setBordure     ( 2 );
//    boutonC->lier           ( gui::Evenements::onChangeEtat , [this]() {
//        m_lblTest->setTexte( "Bouton à cocher : gui::BoutonCocher"  );
//    });
//
//
//
//
//    // alignement des boutons
//    boutonA->setSize        ( { boutonB->getSize().y , boutonB->getSize().y } );
//    boutonB->setPosition    ( boutonA->getPosition().x + boutonA->getSize().x + 10 , 50 );
//    boutonC->setPosition    ( boutonB->getPosition().x + boutonB->getSize().x + 10 , 50 );
//


    // creation de la fenetre
    this->fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
    m_gui.ajouter           ( this->fenetreA );
    this->fenetreA->setPosition   (  20, 300  );
    this->fenetreA->setSize       ( {150, 150} );
    // fenetreA->setSkin ( skinCourant );


    // creation  Bouton pr fenetre, c'est un shared_ptr de l'ecranDemo
    std::shared_ptr<gui::BoutonTexte>  boutonA ( new gui::BoutonTexte ( skinCourant ) );
    this->fenetreA->ajouter ( boutonA );
    boutonA->setPosition    ( 0, 0 );
    boutonA->setSize        ( {30, 30} );
    boutonA->lier  ( gui::Evenements::onGRelache , [this](){
                    std::cout << "cliclic\n";
                    });

    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblFENETRE ( new gui::Label ( "Ceci est un label : gui::Label" , skinCourant->lblCourant ) );
    this->fenetreA->ajouter    ( m_lblFENETRE );
    m_lblFENETRE->aligner    ( *boutonA , gui::Alignements::Ctre_Gche );

    m_lblFENETRE->move    ( 20, 0 );



}   // fin init GUI




}   // fin namespace app































