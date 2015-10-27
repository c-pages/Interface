
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/Fenetre.h>
#include <gadgets/Groupe.h>
#include <gadgets/Label.h>
#include <gadgets/Bouton.h>
#include <gadgets/Image.h>
#include <cmath>

namespace gui {
/*
/////////////////////////////////////////////////
Fenetre::Fenetre( sf::RenderWindow  * fenetre )
: Gadget                   ( )
, m_fenetreSFML     ( fenetre )
, m_bordure         ( 9 )
, m_taille          ( { 150 , 50 } )
, m_skinBtn         ( new Skin() )

, m_deplacable             ( false )
, m_redimensionnable       ( false )
, m_fermable               ( false )

, m_lblTitre               (  )
, m_lblFermer              (  )
, m_btnFermer              (  )
, m_btnDrag                (  )
, m_btnRedimBasDroite      (  )
, m_btnRedimBasGauche      (  )
, m_btnRedimHautDroite     (  )
, m_btnRedimHautGauche     (  )
, m_btnRedimGauche         (  )
, m_btnRedimDroite         (  )
, m_btnRedimBas            (  )
, m_btnRedimHaut           (  )
, m_grpContenu             (  )
, m_CadreContenu           (  )
, m_contenu                ( new sf::Sprite )
, m_fond                   (  )


, m_dragging        ( false )
, m_redimDroite     ( false )
, m_redimGauche     ( false )
, m_redimBas        ( false )
, m_redimHaut       ( false )
{
    init();
}
*/

/////////////////////////////////////////////////
Fenetre::Fenetre(   sf::RenderWindow  *     fenetre
                ,   std::shared_ptr<Skin>   skin    )
: Gadget ( skin )
, m_fenetreSFML     ( fenetre )
, m_bordure         ( 9 )
, m_taille          ( { 150 , 50 } )
, m_skinBtn         ( new Skin() )

, m_deplacable             ( true )
, m_redimensionnable       ( true )
, m_fermable               ( true )

, m_lblTitre               (  )
, m_lblFermer              (  )
, m_btnFermer              (  )
, m_btnDrag                (  )
, m_btnRedimBasDroite      (  )
, m_btnRedimBasGauche      (  )
, m_btnRedimHautDroite     (  )
, m_btnRedimHautGauche     (  )
, m_btnRedimGauche         (  )
, m_btnRedimDroite         (  )
, m_btnRedimBas            (  )
, m_btnRedimHaut           (  )
, m_grpContenu             (  )
, m_CadreContenu           (  )
, m_contenu                ( new sf::Sprite )
, m_fond                   (  )


, m_dragging        ( false )
, m_redimDroite     ( false )
, m_redimGauche     ( false )
, m_redimBas        ( false )
, m_redimHaut       ( false )
{
    init();
}


/////////////////////////////////////////////////
Fenetre::Fenetre(   sf::RenderWindow *  fenetre
                ,   sf::Vector2f        taille
                ,   bool                depl
                ,   bool                ferm
                ,   bool                redim    )
: m_fenetreSFML     ( fenetre )
, m_bordure         ( 9 )
, m_taille          ( taille )
, m_skinBtn         ( new Skin() )

, m_deplacable             ( depl )
, m_redimensionnable       ( redim )
, m_fermable               ( ferm )
, m_lblTitre               (  )
, m_lblFermer              (  )
, m_btnFermer              (  )
, m_btnDrag                (  )
, m_btnRedimBasDroite      (  )
, m_btnRedimBasGauche      (  )
, m_btnRedimHautDroite     (  )
, m_btnRedimHautGauche     (  )
, m_btnRedimGauche         (  )
, m_btnRedimDroite         (  )
, m_btnRedimBas            (  )
, m_btnRedimHaut           (  )
, m_grpContenu             (  )
, m_CadreContenu           (  )
, m_contenu         ( new sf::Sprite )
, m_fond                   (  )


, m_dragging        ( false )
, m_redimDroite     ( false )
, m_redimGauche     ( false )
, m_redimBas        ( false )
, m_redimHaut       ( false )
{
    std::cout << "---- Fenetre ---- 1 ----\n";
    init();
    std::cout << "---- Fenetre ---- 2 ----\n";
}

void
Fenetre::init()
{

    std::cout << "---- Fenetre ---- init ---- 0 ----\n";
    // le fond
    m_fond = std::shared_ptr<Image>   ( new Image    ( ) );
    std::cout << "---- Fenetre ---- init ---- 1 ----\n";
   //

    std::cout << "---- Fenetre ---- init ---- 2 ----\n";



    // création des gadgets pour l'interface de la fenêtre
    m_lblTitre              = std::shared_ptr<Label>   ( new Label    ( "Fenêtre" , m_skin->fenetre ) );
    m_lblFermer             = std::shared_ptr<Label>   ( new Label    ( "X"       , m_skin->fenetre ) );
    m_btnFermer             = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnDrag               = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimBasDroite     = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimBasGauche     = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimHautDroite    = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimHautGauche    = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimGauche        = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimDroite        = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimBas           = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
    m_btnRedimHaut          = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );

    std::cout << "---- Fenetre ---- init ---- 3 ----\n";

    // le cadre autour du group contenant
    m_CadreContenu          = std::shared_ptr<Image>   ( new Image    ( ) );
    std::cout << "---- Fenetre ---- init ---- 4 ----\n";


    // groupe d'affichage, le contenu des élements de la fenêtre
    m_grpContenu  = std::shared_ptr<Groupe>  ( new Groupe   ( ) );
    m_grpContenu->setParent (this);

    // initialiser le skin pour les boutons de l'ui de la fenetre ( genre les boutons drag, redim ... )
    initSkinBouton ();

    // creation de l'interface (boutons drag, redim, ... ) et liaisons des evenements necessaire pour l'interacrtivité de la fenêtre.
    initUI();

    // mizse a jour des styles pour l'ui
    updateStyle();

    // Declenchement de l'évenement d'ouverture de la fenetre;
    declencher ( Evenements::onFen_Ouvre );

    std::cout << "---- Fenetre ---- init ---- fin ----\n";
}


/////////////////////////////////////////////////
Fenetre::~Fenetre()
{

}


/////////////////////////////////////////////////
void
Fenetre::initUI(){

    m_bordure    = 7;


    ajouterUI( m_fond );
    ajouterUI( m_CadreContenu );
    ajouterUI( m_lblTitre );


    // les boutons en options
    if (m_deplacable)         initUI_drag();
    if (m_redimensionnable)   initUI_redim();
    if (m_fermable)           initUI_fermer();



    // actualiser les geometries
    majGeom ();

}



/////////////////////////////////////////////////
void
Fenetre::initUI_drag()
{
    //  heritages
    ajouterUI(  m_btnDrag  );

    //  fonctions
    m_fctDragDebut = [this](){
        m_dragging          = true;
        m_posFenetreOrig    = getPosition();
        m_posMouseOrig      = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctDragFin = [this](){
        if ( m_dragging )
            m_dragging  = false;
    };
    m_fctDragEntre = [this](){
        m_lblTitre->setColor( m_skin->fenetre->txt_couleur );
    };
    m_fctDragSort = [this](){
        m_lblTitre->setColor(  m_skin->fenetre->txt_couleur );
    };

    //  liaisons evenements
    m_btnDrag->lier ( Evenements::onBtnG_Press          , m_fctDragDebut  );
    m_btnDrag->lier ( Evenements::onBtnG_Relache        , m_fctDragFin    );
    m_btnDrag->lier ( Evenements::onBtnG_RelacheDehors  , m_fctDragFin    );
    m_btnDrag->lier ( Evenements::onBtn_Entre           , m_fctDragEntre  );
    m_btnDrag->lier ( Evenements::onBtn_Sort            , m_fctDragSort   );
}

/////////////////////////////////////////////////
void
Fenetre::initUI_fermer()
{
    // heritages
    ajouterUI( m_btnFermer );
    ajouterUI( m_lblFermer );

    // fonctions
    m_fctFermer   =[this](){
        supprimer();
        declencher ( Evenements::onFen_Ferme );
    };
    m_fctFermerEntre = [this](){
        m_lblFermer->setColor( m_skin->fenetre->txt_couleur );
    };
    m_fctFermerSort = [this](){
        m_lblFermer->setColor( m_skin->fenetre->txt_couleur );
    };

    // liaisons evenements
    m_btnFermer->lier        ( Evenements::onBtnG_Relache   , m_fctFermer );
    m_btnFermer->lier        ( Evenements::onBtn_Entre      , m_fctFermerEntre );
    m_btnFermer->lier        ( Evenements::onBtn_Sort       , m_fctFermerSort );
}


/////////////////////////////////////////////////
void
Fenetre::initUI_redim()
{
    // heritages
    ajouterUI( m_btnRedimBasDroite );
    ajouterUI( m_btnRedimBasGauche );
    ajouterUI( m_btnRedimHautDroite );
    ajouterUI( m_btnRedimHautGauche );
    ajouterUI( m_btnRedimGauche );
    ajouterUI( m_btnRedimDroite );
    ajouterUI( m_btnRedimBas );
    ajouterUI( m_btnRedimHaut );

    // fonctions
    m_fctRedimDroiteDebut = [this](){
        m_redimDroite            = true;
        m_tailleFenetreOrig      = m_taille;
        m_posMouseOrig          = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctRedimDroiteFin = [this](){
        m_redimDroite            = false;
    };
    m_fctRedimGaucheDebut = [this](){
        m_redimGauche         = true;
        m_posFenetreOrig      = getPosition();
        m_tailleFenetreOrig   = m_taille;
        m_posMouseOrig        = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctRedimGaucheFin = [this](){
        m_redimGauche            = false;
    };

    m_fctRedimHautDebut = [this](){
        m_redimHaut           = true;
        m_posFenetreOrig      = getPosition();
        m_tailleFenetreOrig   = m_taille;
        m_posMouseOrig        = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctRedimHautFin = [this](){
        m_redimHaut           = false;
    };

    m_fctRedimBasDebut = [this](){
        m_posFenetreOrig     = getPosition();
        m_redimBas            = true;
        m_tailleFenetreOrig   = m_taille;
        m_posMouseOrig        = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctRedimBasFin = [this](){
        m_redimBas            = false;
    };

    m_fctRedimBasDroiteDebut = [this](){
        m_fctRedimDroiteDebut();
        m_fctRedimBasDebut();
    };
    m_fctRedimBasDroiteFin = [this](){
        m_fctRedimDroiteFin();
        m_fctRedimBasFin();
    };
    m_fctRedimBasGaucheDebut = [this](){
        m_fctRedimGaucheDebut();
        m_fctRedimBasDebut();
    };
    m_fctRedimBasGaucheFin = [this](){
        m_fctRedimGaucheFin();
        m_fctRedimBasFin();
    };

    m_fctRedimHautDroiteDebut = [this](){
        m_fctRedimDroiteDebut();
        m_fctRedimHautDebut();
    };
    m_fctRedimHautDroiteFin = [this](){
        m_fctRedimDroiteFin();
        m_fctRedimHautFin();
    };
    m_fctRedimHautGaucheDebut = [this](){
        m_fctRedimGaucheDebut();
        m_fctRedimHautDebut();
    };
    m_fctRedimHautGaucheFin = [this](){
        m_fctRedimGaucheFin();
        m_fctRedimHautFin();
    };


    // liaisons evenements
    m_btnRedimBasDroite->lier ( Evenements::onBtnG_Press            , m_fctRedimBasDroiteDebut );
    m_btnRedimBasDroite->lier ( Evenements::onBtnG_Relache          , m_fctRedimBasDroiteFin  );
    m_btnRedimBasDroite->lier ( Evenements::onBtnG_RelacheDehors    , m_fctRedimBasDroiteFin );

    m_btnRedimBasGauche->lier ( Evenements::onBtnG_Press            , m_fctRedimBasGaucheDebut );
    m_btnRedimBasGauche->lier ( Evenements::onBtnG_Relache          , m_fctRedimBasGaucheFin );
    m_btnRedimBasGauche->lier ( Evenements::onBtnG_RelacheDehors    , m_fctRedimBasGaucheFin );


    m_btnRedimHautDroite->lier ( Evenements::onBtnG_Press           , m_fctRedimHautDroiteDebut );
    m_btnRedimHautDroite->lier ( Evenements::onBtnG_Relache         , m_fctRedimHautDroiteFin  );
    m_btnRedimHautDroite->lier ( Evenements::onBtnG_RelacheDehors   , m_fctRedimHautDroiteFin );

    m_btnRedimHautGauche->lier ( Evenements::onBtnG_Press           , m_fctRedimHautGaucheDebut );
    m_btnRedimHautGauche->lier ( Evenements::onBtnG_Relache         , m_fctRedimHautGaucheFin );
    m_btnRedimHautGauche->lier ( Evenements::onBtnG_RelacheDehors   , m_fctRedimHautGaucheFin );



    m_btnRedimDroite->lier ( Evenements::onBtnG_Press               , m_fctRedimDroiteDebut );
    m_btnRedimDroite->lier ( Evenements::onBtnG_Relache             , m_fctRedimDroiteFin );
    m_btnRedimDroite->lier ( Evenements::onBtnG_RelacheDehors       , m_fctRedimDroiteFin );

    m_btnRedimGauche->lier ( Evenements::onBtnG_Press               , m_fctRedimGaucheDebut );
    m_btnRedimGauche->lier ( Evenements::onBtnG_Relache             , m_fctRedimGaucheFin );
    m_btnRedimGauche->lier ( Evenements::onBtnG_RelacheDehors       , m_fctRedimGaucheFin );

    m_btnRedimBas->lier ( Evenements::onBtnG_Press                  , m_fctRedimBasDebut );
    m_btnRedimBas->lier ( Evenements::onBtnG_Relache                , m_fctRedimBasFin );
    m_btnRedimBas->lier ( Evenements::onBtnG_RelacheDehors          , m_fctRedimBasFin );

    m_btnRedimHaut->lier ( Evenements::onBtnG_Press                  , m_fctRedimHautDebut );
    m_btnRedimHaut->lier ( Evenements::onBtnG_Relache                , m_fctRedimHautFin );
    m_btnRedimHaut->lier ( Evenements::onBtnG_RelacheDehors          , m_fctRedimHautFin );
}


/////////////////////////////////////////////////
void
Fenetre::initSkinBouton (){

    m_skinBtn =   std::make_shared<gui::Skin> () ;

    sf::Color transparent =  sf::Color  ( 255,255,255 , 0 );

    //// BOUTON REPOS ///////////////////////////////////
    m_skinBtn->btnRepos->txt_style         = sf::Text::Style::Regular ;
    m_skinBtn->btnRepos->txt_taille        = 10;
    m_skinBtn->btnRepos->txt_couleur       = transparent;
    m_skinBtn->btnRepos->lgn_epaisseur     = 0;
    m_skinBtn->btnRepos->lgn_couleur       = transparent;
    m_skinBtn->btnRepos->fnd_couleur       = sf::Color  ( 255,255,255 , 0 );
    m_skinBtn->btnRepos->fnd_texture       = sf::Texture ();
    m_skinBtn->btnRepos->align             = gui::Alignements::Libre;
    m_skinBtn->btnRepos->ajust             = gui::Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    m_skinBtn->btnSurvol->txt_style        = sf::Text::Style::Regular;
    m_skinBtn->btnSurvol->txt_taille       = 10;
    m_skinBtn->btnSurvol->txt_couleur      = transparent;
    m_skinBtn->btnSurvol->lgn_epaisseur    = 0;
    m_skinBtn->btnSurvol->lgn_couleur      = transparent;
    m_skinBtn->btnSurvol->fnd_couleur      = sf::Color  ( 255,255,255 , 20 );
    m_skinBtn->btnSurvol->fnd_texture      = sf::Texture ();
    m_skinBtn->btnSurvol->align            = gui::Alignements::Libre;
    m_skinBtn->btnSurvol->ajust            = gui::Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    m_skinBtn->btnPress->txt_style         = sf::Text::Style::Regular;
    m_skinBtn->btnPress->txt_taille        = 10;
    m_skinBtn->btnPress->txt_couleur       = transparent;
    m_skinBtn->btnPress->lgn_epaisseur     = 0;
    m_skinBtn->btnPress->lgn_couleur       = transparent;
    m_skinBtn->btnPress->fnd_couleur       = sf::Color  ( 255,255,255 , 40 );
    m_skinBtn->btnPress->fnd_texture       = sf::Texture ();
    m_skinBtn->btnPress->align             = gui::Alignements::Libre;
    m_skinBtn->btnPress->ajust             = gui::Ajustements::Sans;

}


/////////////////////////////////////////////////
void
Fenetre::updateStyle( ){

    m_btnDrag->setSkin              ( m_skinBtn ) ;
    m_btnFermer->setSkin            ( m_skinBtn ) ;
    m_btnRedimBasDroite->setSkin    ( m_skinBtn ) ;
    m_btnRedimBasGauche->setSkin    ( m_skinBtn ) ;
    m_btnRedimHautDroite->setSkin   ( m_skinBtn ) ;
    m_btnRedimHautGauche->setSkin   ( m_skinBtn ) ;
    m_btnRedimDroite->setSkin       ( m_skinBtn ) ;
    m_btnRedimGauche->setSkin       ( m_skinBtn ) ;
    m_btnRedimBas->setSkin          ( m_skinBtn ) ;
    m_btnRedimHaut->setSkin         ( m_skinBtn ) ;

    //// Titre ///////////////////////////////////
    m_lblTitre->setStyle            ( m_skin->fenetre );
    m_lblFermer->setStyle           ( m_skin->fenetre );

    //// fond ///////////////////////////////////
    m_fond->setStyle                ( m_skin->fenetre );
    m_CadreContenu->setStyle        ( m_skin->cadre );
};


/////////////////////////////////////////////////
sf::Vector2f
Fenetre::getSize ( ){
    return   {   getGlobalBounds().width
             ,   getGlobalBounds().height };
};


/////////////////////////////////////////////////
sf::FloatRect
Fenetre::getLocalBounds ( ) {
    return  m_fond->getLocalBounds() ;
}


/////////////////////////////////////////////////
sf::FloatRect
Fenetre::getGlobalBounds ( ) {
    sf::FloatRect result( m_fond->getGlobalBounds() );

    result.left     =  getPosAbs().x - m_bordure;
    result.top      =  getPosAbs().y - ( m_lblTitre->getSize().y +  ( 2 * m_bordure ));

    return { result };
}


/////////////////////////////////////////////////
void
Fenetre::setTexte ( std::string titre)            {
    m_lblTitre->setTexte( titre );
    majGeom ();
};


/////////////////////////////////////////////////
std::string
Fenetre::getTexte (  ){
    return m_lblTitre->getTexte();
}


/////////////////////////////////////////////////
void
Fenetre::ajouterUI( ptr enfant ) {

    m_enfants.push_back ( enfant );
    enfant->setParent (this);
    majGeom ();
};


/////////////////////////////////////////////////
void
Fenetre::ajouter( ptr enfant ) {

    m_grpContenu->ajouter(  enfant );

    majGeom ();
};


/////////////////////////////////////////////////
void
Fenetre::ManipulerFenetre ( )    {


    // > Actualiser le Drag
    if ( m_deplacable and m_dragging ) {
        sf::Vector2f    mousePos = sf::Vector2f   ( sf::Mouse::getPosition( *m_fenetreSFML ) ) ;
        setPosition     ( m_posFenetreOrig +  mousePos - m_posMouseOrig );
    }

    // > Actualiser le Redim
    if (m_redimensionnable)  {

        // les mimimums
        float minY = 1;;
        float minX = m_lblTitre->getSize().x + m_btnFermer->getSize().x + 2 * m_bordure;

        // la position de la souris
        sf::Vector2f  mousePos      = sf::Vector2f   ( sf::Mouse::getPosition( *m_fenetreSFML ) ) ;
        sf::Vector2f  depl_Souris   = mousePos - m_posMouseOrig;

        /////////////////////////////////////////////////
        if ( m_redimDroite ) {
            // la nouvelle dimension sur X = l'ancienne dimension X + le deplacement de la souris sur X.
            m_taille.x = m_tailleFenetreOrig.x + ( depl_Souris.x );
            if ( m_taille.x < minX ) m_taille.x = minX ;
        }

        /////////////////////////////////////////////////
        if ( m_redimBas ) {
            // la nouvelle dimension sur Y = l'ancienne dimension Y + le deplacement de la souris sur Y.
            m_taille.y = m_tailleFenetreOrig.y + (  depl_Souris.y     );
            if ( m_taille.y < minY ) m_taille.y = minY ;
        }

        /////////////////////////////////////////////////
        if ( m_redimHaut && m_redimGauche ) {
            // la nouvelle position = l'ancienne position  + le deplacement de la souris.
            setPosition ( m_posFenetreOrig.x +  depl_Souris.x
                        , m_posFenetreOrig.y +  depl_Souris.y);

            // la nouvelle dimension = l'ancienne dimension  - le deplacement de la souris.
            m_taille.x = m_tailleFenetreOrig.x - (  depl_Souris.x     );
            m_taille.y = m_tailleFenetreOrig.y - (  depl_Souris.y     );
        }

        /////////////////////////////////////////////////
        else if ( m_redimHaut ) {
            // la nouvelle position sur Y = l'ancienne position sur Y   + le deplacement de la souris sur Y .
            setPosition ( m_posFenetreOrig.x
                        , m_posFenetreOrig.y +  depl_Souris.y ) ;

            // la nouvelle dimension sur Y = l'ancienne dimension  sur Y - le deplacement de la souris sur Y .
            m_taille.y = m_tailleFenetreOrig.y - (  depl_Souris.y     );
        }

        /////////////////////////////////////////////////
        else if ( m_redimGauche ) {
            // la nouvelle position sur X = l'ancienne position sur X   + le deplacement de la souris sur X .
            setPosition ( m_posFenetreOrig.x +  depl_Souris.x
                        , m_posFenetreOrig.y);
            // la nouvelle dimension sur X = l'ancienne dimension  sur X - le deplacement de la souris sur X .
            m_taille.x = m_tailleFenetreOrig.x - (  depl_Souris.x     );
        }

        /////////////////////////////////////////////////
        // corrections des tailles minimum
        if ( m_taille.x < minX ) {
            setPosition ( m_posFenetreOrig.x +  m_tailleFenetreOrig.x - minX
                        , getPosition().y );
            m_taille.x = minX ;
        }
        if ( m_taille.y < minY ) {
            setPosition ( getPosition().x
                        , m_posFenetreOrig.y  +  m_tailleFenetreOrig.y - minY );
            m_taille.y = minY ;
        }

    } // fin si redimensionnable


    /////////////////////////////////////////////////
    // S'il y a eu manipulation on met à jour la géométrie.
    if ( m_redimDroite   or  m_redimBas  or  m_redimGauche or  m_redimHaut)
        majGeom ();


}





/////////////////////////////////////////////////
void
Fenetre::majGeom ()    {

    updateStyle( );

    /*
    // ///// Position des reperes dans la fenetre /////////////////////////////////////////
    //                                                                                   //
    //                HORIZ_...                                                          //
    //                                                                                   //
    //  VERTI_...     0    1                 3     2    4                                //
    //                |    |                 |     |    |                                //
    //      0 ---     |----|-----------------------|----|  ---                           //
    //                |Red.|      Redimension      |Red.|      m_bordure                 //
    //      1 ---     |----|-----------------|-----|----|  ---                           //
    //                |    |                 |     |    |      hauteurTitre              //
    //                |    |  Titre/drag     |Ferm.|    |  ---                           //
    //                |    |                 |     |    |      m_bordure                 //
    //      2 ---     |   0.0----------------|-----|    |  ---                           //
    //                |Red.|                       |Red.|                                //
    //                |    |                       |    |                                //
    //                |    |      Contenu          |    |      taille.y                  //
    //                |    |      ( taille )       |    |                                //
    //                |    |                       |    |                                //
    //      3 ---     |----|-----------------------|----|  ---                           //
    //                |Red.|      Redimemsion      |Red.|      m_bordure                 //
    //      4 ---     |----|-----------------------|----|  ---                           //
    //                                                                                   //
    //                |    |                       |    |                                //
    //               m_bordure      taille.x      m_bordure                              //
    //                                                                                   //
    ///////////////////////////////////////////////////////////////////////////////////////
    */


    /////  les repères ///////////////

    float hauteurTitre = m_lblTitre->getSize().y;

    float horiz_0  = - m_bordure ;
    float horiz_1  = 0 ;
    float horiz_2  =  m_taille.x;
   // float horiz_4   = horiz_2 + m_bordure ;
    float horiz_total = horiz_2 + 2 * m_bordure ;

    float verti_0 = - ( hauteurTitre +  (2 * m_bordure ) ) ;
    float verti_1 = - ( hauteurTitre +  m_bordure  ) ;
    float verti_2 = 0 ;
    float verti_3 = m_taille.y  ;
    float verti_total = verti_3 + m_bordure  + std::abs( verti_0 ) ;

    float horiz_3  = horiz_2  - std::abs( verti_1 ) - m_bordure;

    //  le fond
    m_fond->setPosition          ( horiz_0 , verti_0 );
    m_fond->setSize              ( { horiz_total , verti_total  }    );
    m_CadreContenu->setPosition  ( horiz_1 , verti_2 );
    m_CadreContenu->setSize      ( { m_taille.x  , m_taille.y  }    );

    //  le Contenu
    m_contenu->setPosition       ( horiz_1 , verti_2 );
    m_grpContenu->setPosition    ( horiz_1 , verti_2 );

    //  le bouton drag
    if ( m_deplacable ) {
        if ( m_fermable )
            m_btnDrag->setSize   ( { m_taille.x - std::abs( verti_1 )  , std::abs( verti_1 )} );
        else
            m_btnDrag->setSize   ( { m_taille.x  , std::abs( verti_1 ) } );
        m_btnDrag->setPosition   ( { horiz_1 , verti_1 } );
    }

    //  les boutons redimmensionnement
    if ( m_redimensionnable ) {

        // les coins
        m_btnRedimBasGauche->setSize        ( { m_bordure   , m_bordure } );
        m_btnRedimBasGauche->setPosition    ( { horiz_0     , verti_3 } );
        m_btnRedimBasDroite->setSize        ( { m_bordure   , m_bordure } );
        m_btnRedimBasDroite->setPosition    ( { horiz_2     , verti_3 } );
        m_btnRedimHautGauche->setSize       ( { m_bordure   , m_bordure } );
        m_btnRedimHautGauche->setPosition   ( { horiz_0     , verti_0 } );
        m_btnRedimHautDroite->setSize       ( { m_bordure   , m_bordure } );
        m_btnRedimHautDroite->setPosition   ( { horiz_2     , verti_0 } );

        // les arretes
        m_btnRedimGauche->setSize           ( { m_bordure   , verti_total - 2* m_bordure } );
        m_btnRedimGauche->setPosition       ( { horiz_0     , verti_1 } );
        m_btnRedimDroite->setSize           ( { m_bordure   , verti_total - 2* m_bordure } );
        m_btnRedimDroite->setPosition       ( { horiz_2     ,  verti_1 } );
        m_btnRedimBas->setSize              ( { m_taille.x  , m_bordure } );
        m_btnRedimBas->setPosition          ( { horiz_1   , verti_3 } );
        m_btnRedimHaut->setSize             ( { m_taille.x  , m_bordure } );
        m_btnRedimHaut->setPosition         ( { horiz_1   , verti_0 } );

    }

    //  le titre
    m_lblTitre->aligner ( *m_btnDrag , Alignements::Ctre_Gche );

    //  le bouton fermer
    if ( m_fermable ) {
        m_btnFermer->setSize      ( { std::abs( verti_1 ) , std::abs( verti_1 ) } );
        m_btnFermer->setPosition  ( { horiz_3 +m_bordure, verti_1 } );
        m_lblFermer->aligner      ( *m_btnFermer  , Alignements::Ctre_Mili );
        m_lblFermer->setPosition  ( { m_lblFermer->getPosition().x , m_lblTitre->getPosition().y } );
    }
    updateStyle( );
}


/////////////////////////////////////////////////
void
Fenetre::traiter_evenements ( const sf::Event& event ) {

    m_grpContenu->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}



/////////////////////////////////////////////////
void
Fenetre::actualiser ( float deltaT )    {

    // > Drag et redimensionnements
    ManipulerFenetre ();

    // > Actualiser niveau Gadget
    Gadget::actualiser          ( deltaT );

    // > Actualiser le contenu de la fenetre
    m_grpContenu->actualiser    ( deltaT );
}


/////////////////////////////////////////////////
void
Fenetre::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();

    // dessiner les éléments de l'UI de la fenetre
    for ( ptr enfant : m_enfants )
        target.draw      ( *enfant , states );

    // la texture dans laquelle on va dessiner les éléments contenus
    sf::RenderTexture       texture;
    if ( texture.create   ( m_taille.x , m_taille.y ) ) {

        //dessin du contenu dans la texture
        texture.clear     ( m_skin->invisible->fnd_couleur );
        texture.draw      ( *m_grpContenu );
        texture.display   ( );

        //Appliquer la texture au sprite qui va l'afficher.
        m_contenu->setTexture    ( texture.getTexture() );
        m_contenu->setTextureRect( sf::IntRect(0, 0, m_taille.x , m_taille.y  ) );
    }

    //dessiner le sprite dans la fenêtre.
    target.draw      ( *m_contenu , states );

}


}
















