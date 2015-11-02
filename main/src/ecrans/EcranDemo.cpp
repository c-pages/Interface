

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
}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...

    // Evenements de l'interface
    m_gui->traiter_evenements    ( event );
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
    m_appli->getFenetre().draw ( m_fond );

    // Dessiner l'interface
    m_appli->getFenetre().draw ( *m_gui);
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
EcranDemo::initGUI  ( )
{

    // le skin qu'on va utiliser dans cette interface
    auto skinCourant =  Config::m_skins[ Config::Skins::Skin1 ] ;



    std::shared_ptr<gui::Label>  label ( new gui::Label ( "LABEL 1 LABEL 2 LABEL 3 LABEL 4" ) );
    label->setTexteTaille   ( 20 );
    label->setPosition      ( 20 , 50 );

    label->getLocalBounds();
    m_gui->ajouter          ( label );

    label->getLocalBounds();


/*

    // creation de la fenetre
    //fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
    std::shared_ptr<gui::Fenetre>  fenetre ( new gui::Fenetre   ( &m_appli->getFenetre()
                                                                , sf::Vector2f (200, 200) , true, true, true ) );
    m_gui->ajouter          ( fenetre );
    fenetre->setPosition    ( 50 , 50 );
    fenetre->setSkin        ( skinCourant );
    fenetre->setSize        ( { 150 , 400 } ) ; //m_appli->getFenetre().getSize().y }  ); // ( { 150 , m_appli->getFenetre().getSize().y}) ;



    std::shared_ptr<gui::Label>  label2 ( new gui::Label ( "LABEL 1 LABEL 2 LABEL 3 LABEL 4 LABEL 5 LABEL 6 LABEL 7 LABEL 8 LABEL 9 LABEL 10 " ) );
    label2->setTexteTaille   ( 10 );
    label2->setPosition      ( 20 , 350 );


    std::shared_ptr<gui::Label>  label3 ( new gui::Label ( "A" ) );
    label3->setTexteTaille   ( 150 );
    label3->setPosition      ( 50 , 150 );




    label3 = std::shared_ptr<gui::Label>   ( new gui::Label ( "Aopifjzen" )   );
    label3->setTexteTaille   ( 50 );
    label3->setPosition      ( 50 , 150 );
    label3->setStyle      ( skinCourant->lblCourant );
    label3->setTexteTaille      ( 50 );

    std::shared_ptr<gui::BoutonTexte>  boutonT ( new gui::BoutonTexte  ( "TEXTE"  ) );
    boutonT->setPosition ( { 50 , 50 });
    boutonT->setSize ( { 50 , 50 });
*/
//    fenetre->ajouter    ( bouton );
/*
    fenetre->ajouter    ( boutonT );

    fenetre->ajouter      ( label2 );
    fenetre->ajouter      ( label3 );
*/
/*

    labelTest = std::shared_ptr<gui::Label>   ( new gui::Label ( "LABEL ppqq" ) );
    labelTest->setTexteTaille   ( 20 );
    labelTest->setPosition      ( 20 , 50 );


    std::shared_ptr<gui::Bouton>  boutonT ( new gui::Bouton  (  ) );
    boutonT->setPosition ( { 50 , 50 });
    boutonT->setSize ( { 50 , 50 });
    boutonT->lier ( gui::Evenements::onBtnG_Relache , [this](){
                   std::cout << "-----------------------------------\n";
                   labelTest->majGeom( );
                   labelTest->getLocalBounds();
                   std::cout << "-----------------------------------\n";

                   });





    m_gui->ajouter    ( boutonT );
    m_gui->ajouter    ( labelTest );
*/

//labelTest->aligner ( *boutonT , gui::Alignements::Ctre_Mili);


/*
std::cout << "labelTest->getPosition : " << labelTest->getPosition().x << " " <<labelTest->getPosition().y << "\n";

std::cout << "labelTest->getLocalBounds : " << labelTest->getLocalBounds().left << " " <<labelTest->getLocalBounds().top<< " " <<labelTest->getLocalBounds().width<< " " <<labelTest->getLocalBounds().height << "\n";

std::cout << "labelTest->getGlobalBounds : " << labelTest->getGlobalBounds().left << " " <<labelTest->getGlobalBounds().top<< " " <<labelTest->getGlobalBounds().width<< " " <<labelTest->getGlobalBounds().height << "\n";

*/

 //   m_gui->ajouter    ( boutonA );



/*
    m_gui->ajouter    ( label3 );
    m_gui->ajouter    ( bouton );

*/

//bouton->aligner ( *boutonA , gui::Alignements::Ctre_Mili );
//bouton->aligner ( *label3 , gui::Alignements::Ctre_Mili );



/*
    // creation de la fenetre
    //fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
    std::shared_ptr<gui::Fenetre>  fenetre ( new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ));
    m_gui->ajouter          ( fenetre );
    fenetre->setPosition    ( 20 , 20 );
    fenetre->setSize        ( { 250 , 250 } ) ; //m_appli->getFenetre().getSize().y }  ); // ( { 150 , m_appli->getFenetre().getSize().y}) ;
*/
//
//    // creation de la fenetre
//    //fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
//    std::shared_ptr<gui::Fenetre_encastree>  fenetre_encastree ( new gui::Fenetre_encastree ( &m_appli->getFenetre() , skinCourant  , gui::Encastrements::Droite ));
//    m_gui->ajouter              ( fenetre_encastree );
//    fenetre_encastree->setPosition    ( 0 ,0 );
//    fenetre_encastree->setSize       ( { 250 , m_appli->getFenetre().getSize().y }  ); // ( { 150 , m_appli->getFenetre().getSize().y}) ;

/*

    // creation  Bouton pr fenetre, c'est un shared_ptr de l'ecranDemo
    std::shared_ptr<gui::BoutonTexte>  boutonA ( new gui::BoutonTexte (skinCourant ,  "gui::BoutonTexte" ) );
    fenetre_encastree->ajouter    ( boutonA );
  //  boutonA->setPosition    ( 0, 0 );
  //  boutonA->setBordure     ( 3 )  ;
   // boutonA->ajusterAuTexte ( );

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

*/
/*
    // creation  Bouton Slide
    std::shared_ptr<gui::BoutonSlide>  boutonSlide ( new gui::BoutonSlide  ( gui::Orientation::Verticale
                                                                           , skinCourant
                                                                           , 500 ) );
    fenetre->ajouter    ( boutonSlide );
    std::cout << "ecran ---- 1 ----\n";
    boutonSlide->setPosition ( { 50 , 50 } );
*/


   // boutonSlide->lier           ( gui::Evenements::onBtnG_DblClique         , [this]() {  std::cout << "-->  onBtnG_DblClique\n";   });





    std::cout << "ecran : fin init()\n";



/*
   // gui::Fenetre::

    // creation de la fenetre
    //fenetreA = std::shared_ptr<gui::Fenetre> (  new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ) );
    std::shared_ptr<gui::Fenetre>  fenetreA ( new gui::Fenetre ( &m_appli->getFenetre() , skinCourant ));
    m_gui->ajouter          ( fenetreA );
    fenetreA->setPosition   (  250, 250  );
    fenetreA->setSize       ( {420, 100} );
    fenetreA->setBordure    ( 6 );
    // fenetreA->setSkin ( skinCourant );
    fenetreA->setTexte      ("Ceci est une gui::Fenetre");
    fenetreA->lier          ( gui::Evenements::onFen_Ouvre              , [this]() {  std::cout << "gui::Fenetre ->  onFen_Ouvre\n";   });
    fenetreA->lier          ( gui::Evenements::onFen_Ferme              , [this]() {  std::cout << "gui::Fenetre ->  onFen_Ferme\n";   });


  //  std::cout << "TITRE : " << fenetreA->getTexte (  ) << "\n";




    // creation  Bouton pr fenetre, c'est un shared_ptr de l'ecranDemo
    std::shared_ptr<gui::BoutonTexte>  boutonA ( new gui::BoutonTexte (skinCourant ,  "       gui::BoutonTexte      " ) );
    fenetreA->ajouter ( boutonA );
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


    // creation du BoutonTexte B, nouveau pointeur, ajouté aux enfants du groupe GUI principal.
    std::shared_ptr<gui::Bouton>  boutonC ( new gui::Bouton ( skinCourant ) );
    fenetreA->ajouter           ( boutonC );
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
    fenetreA->ajouter    ( m_lblFENETRE );
    m_lblFENETRE->setPosition ( 15, 5 );


    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblC ( new gui::Label ( "<-- gui::Bouton, simple bouton rectangulaire" , skinCourant->lblCourant ) );
    fenetreA->ajouter    ( m_lblC );
    m_lblC->aligner ( *boutonC );
    m_lblC->setPosition( 30 , int( m_lblC->getPosition().y)  );



    // creation du BoutonTexte B, nouveau pointeur, ajouté aux enfants du groupe GUI principal.
    std::shared_ptr<gui::BoutonEncoche>  boutonD ( new gui::BoutonEncoche ( skinCourant ) );
    fenetreA->ajouter           ( boutonD );
    boutonD->setPosition    ( 15, 50 );
    boutonD->setSize        ( { boutonA->getSize().y , boutonA->getSize().y } );
    boutonD->setBordure     ( 2 );

    boutonD->lier           ( gui::Evenements::onBtnG_DblClique         , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnG_DblClique\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_Press             , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnG_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_Relache           , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnG_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnG_RelacheDehors     , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnG_RelacheDehors\n";   });

    boutonD->lier           ( gui::Evenements::onBtnD_Press             , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnD_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnD_Relache           , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnD_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnD_RelacheDehors     , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnD_RelacheDehors\n";   });

    boutonD->lier           ( gui::Evenements::onBtnM_Press             , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnM_Press\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_Relache           , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnM_Relache\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RelacheDehors     , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnM_RelacheDehors\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RollDown          , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnM_RollDown\n";   });
    boutonD->lier           ( gui::Evenements::onBtnM_RollUp            , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtnM_RollUp\n";   });

    boutonD->lier           ( gui::Evenements::onBtn_Entre              , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtn_Entre\n";   });
    boutonD->lier           ( gui::Evenements::onBtn_Sort               , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtn_Sort\n";   });

    boutonD->lier           ( gui::Evenements::onBtn_changeEtat         , [this]() {  std::cout << "gui::BoutonEncoche ->  onBtn_changeEtat\n";   });



    // creation d'un label a mettre dans le fenetre
    std::shared_ptr<gui::Label>  m_lblD ( new gui::Label ( "<-- ui::BoutonEncoche, bouton boolean" , skinCourant->lblCourant ) );
    fenetreA->ajouter    ( m_lblD );
    m_lblD->aligner ( *boutonD );
    m_lblD->setPosition( 30 , int (m_lblD->getPosition().y) );
*/

}   // fin init GUI




}   // fin namespace app































