

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
    m_fond.setFillColor ( sf::Color (40,40,50));
}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ( )
{
    // le skin qu'on va utiliser dans cette interface
    auto skinCourant =  Config::m_skins[ Config::Skins::Skin1 ] ;



    // creation de la fenetre
    this->fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
    m_gui.ajouter           ( this->fenetreA );
    this->fenetreA->setPosition  (  250, 250  );
    this->fenetreA->setSize       ( {420, 100} );
    this->fenetreA->setBordure     ( 5 );
    // fenetreA->setSkin ( skinCourant );
    this->fenetreA->setTitre("Ceci est une gui::Fenetre");
    this->fenetreA->lier           ( gui::Evenements::onFen_Ouvre              , [this]() {  std::cout << "gui::Fenetre ->  onFen_Ouvre\n";   });
    this->fenetreA->lier           ( gui::Evenements::onFen_Ferme              , [this]() {  std::cout << "gui::Fenetre ->  onFen_Ferme\n";   });








    // creation  Bouton pr fenetre, c'est un shared_ptr de l'ecranDemo
    std::shared_ptr<gui::BoutonTexte>  boutonA ( new gui::BoutonTexte (skinCourant ,  "       gui::BoutonTexte      " ) );
    this->fenetreA->ajouter ( boutonA );
    boutonA->setPosition    ( 15, 75 );
    boutonA->setSize        ( {30, 30} );
    boutonA->setBordure     ( 3 )  ;
    boutonA->ajusterAuTexte ( );

    boutonA->lier           ( gui::Evenements::onBtnG_DblClique         , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnG_DblClique\n";   });
    boutonA->lier           ( gui::Evenements::onBtnG_Press             , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnG_Press\n";   });
    boutonA->lier           ( gui::Evenements::onBtnG_Relache           , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnG_Relache\n";   });
    boutonA->lier           ( gui::Evenements::onBtnG_RelacheDehors     , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnG_RelacheDehors\n";   });

    boutonA->lier           ( gui::Evenements::onBtnD_Press             , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnD_Press\n";   });
    boutonA->lier           ( gui::Evenements::onBtnD_Relache           , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnD_Relache\n";   });
    boutonA->lier           ( gui::Evenements::onBtnD_RelacheDehors     , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnD_RelacheDehors\n";   });

    boutonA->lier           ( gui::Evenements::onBtnM_Press             , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnM_Press\n";   });
    boutonA->lier           ( gui::Evenements::onBtnM_Relache           , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnM_Relache\n";   });
    boutonA->lier           ( gui::Evenements::onBtnM_RelacheDehors     , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnM_RelacheDehors\n";   });
    boutonA->lier           ( gui::Evenements::onBtnM_RollDown          , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnM_RollDown\n";   });
    boutonA->lier           ( gui::Evenements::onBtnM_RollUp            , [this]() {  std::cout << "gui::BoutonTexte ->  onBtnM_RollUp\n";   });

    boutonA->lier           ( gui::Evenements::onBtn_Entre              , [this]() {  std::cout << "gui::BoutonTexte ->  onBtn_Entre\n";   });
    boutonA->lier           ( gui::Evenements::onBtn_Sort               , [this]() {  std::cout << "gui::BoutonTexte ->  onBtn_Sort\n";   });


    // creation du BoutonTexte B, nouveau pointeur, ajout� aux enfants du groupe GUI principal.
    std::shared_ptr<gui::Bouton>  boutonC ( new gui::Bouton ( skinCourant ) );
    this->fenetreA->ajouter           ( boutonC );
    boutonC->setPosition    ( 15, 25 );
    boutonC->setSize        ( { boutonA->getSize().y , boutonA->getSize().y } );
    boutonC->setBordure     ( 2 );

    boutonC->lier           ( gui::Evenements::onBtnG_DblClique         , [this]() {  std::cout << "gui::Bouton ->  onBtnG_DblClique\n";   });
    boutonC->lier           ( gui::Evenements::onBtnG_Press             , [this]() {  std::cout << "gui::Bouton ->  onBtnG_Press\n";   });
    boutonC->lier           ( gui::Evenements::onBtnG_Relache           , [this]() {  std::cout << "gui::Bouton ->  onBtnG_Relache\n";   });
    boutonC->lier           ( gui::Evenements::onBtnG_RelacheDehors     , [this]() {  std::cout << "gui::Bouton ->  onBtnG_RelacheDehors\n";   });

    boutonC->lier           ( gui::Evenements::onBtnD_Press             , [this]() {  std::cout << "gui::Bouton ->  onBtnD_Press\n";   });
    boutonC->lier           ( gui::Evenements::onBtnD_Relache           , [this]() {  std::cout << "gui::Bouton ->  onBtnD_Relache\n";   });
    boutonC->lier           ( gui::Evenements::onBtnD_RelacheDehors     , [this]() {  std::cout << "gui::Bouton ->  onBtnD_RelacheDehors\n";   });

    boutonC->lier           ( gui::Evenements::onBtnM_Press             , [this]() {  std::cout << "gui::Bouton ->  onBtnM_Press\n";   });
    boutonC->lier           ( gui::Evenements::onBtnM_Relache           , [this]() {  std::cout << "gui::Bouton ->  onBtnM_Relache\n";   });
    boutonC->lier           ( gui::Evenements::onBtnM_RelacheDehors     , [this]() {  std::cout << "gui::Bouton ->  onBtnM_RelacheDehors\n";   });
    boutonC->lier           ( gui::Evenements::onBtnM_RollDown          , [this]() {  std::cout << "gui::Bouton ->  onBtnM_RollDown\n";   });
    boutonC->lier           ( gui::Evenements::onBtnM_RollUp            , [this]() {  std::cout << "gui::Bouton ->  onBtnM_RollUp\n";   });

    boutonC->lier           ( gui::Evenements::onBtn_Entre              , [this]() {  std::cout << "gui::Bouton ->  onBtn_Entre\n";   });
    boutonC->lier           ( gui::Evenements::onBtn_Sort               , [this]() {  std::cout << "gui::Bouton ->  onBtn_Sort\n";   });





    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblFENETRE ( new gui::Label ( "Ceci est un gui::Label" , skinCourant->lblCourant ) );
    this->fenetreA->ajouter    ( m_lblFENETRE );
    m_lblFENETRE->setPosition ( 15, 1 );


    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblC ( new gui::Label ( "<-- gui::Bouton" , skinCourant->lblCourant ) );
    this->fenetreA->ajouter    ( m_lblC );
    m_lblC->aligner ( *boutonC );
    m_lblC->setPosition( 30 , int( m_lblC->getPosition().y)  );



    // creation du BoutonTexte B, nouveau pointeur, ajout� aux enfants du groupe GUI principal.
    std::shared_ptr<gui::BoutonCocher>  boutonD ( new gui::BoutonCocher ( skinCourant ) );
    this->fenetreA->ajouter           ( boutonD );
    boutonD->setPosition    ( 15, 50 );
    boutonD->setSize        ( { boutonA->getSize().y , boutonA->getSize().y } );
    boutonD->setBordure     ( 2 );

    boutonD->lier           ( gui::Evenements::onBtnG_DblClique         , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnG_DblClique\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_Press             , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnG_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_Relache           , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnG_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_RelacheDehors     , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnG_RelacheDehors\n";   });

    boutonD->lier           ( gui::Evenements::onBtnD_Press             , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnD_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnD_Relache           , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnD_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnD_RelacheDehors     , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnD_RelacheDehors\n";   });

    boutonD->lier           ( gui::Evenements::onBtnM_Press             , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnM_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_Relache           , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnM_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RelacheDehors     , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnM_RelacheDehors\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RollDown          , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnM_RollDown\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RollUp            , [this]() {  std::cout << "gui::BoutonCocher ->  onBtnM_RollUp\n";   });

    boutonD->lier           ( gui::Evenements::onBtn_Entre              , [this]() {  std::cout << "gui::BoutonCocher ->  onBtn_Entre\n";   });
    boutonD->lier           ( gui::Evenements::onBtn_Sort               , [this]() {  std::cout << "gui::BoutonCocher ->  onBtn_Sort\n";   });

    boutonD->lier           ( gui::Evenements::onBtn_changeEtat         , [this]() {  std::cout << "gui::BoutonCocher ->  onBtn_changeEtat\n";   });



    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblD ( new gui::Label ( "<-- ui::BoutonCocher" , skinCourant->lblCourant ) );
    this->fenetreA->ajouter    ( m_lblD );
    m_lblD->aligner ( *boutonD );
    m_lblD->setPosition( 30 , int (m_lblD->getPosition().y) );



}   // fin init GUI




}   // fin namespace app































