
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/Fenetre.h>
#include <../GUI.h>

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
, m_bordure         ( 7 )
, m_taille          ( { 150 , 50 } )
, m_skinBtn         ( new Skin() )

, m_deplacable             ( true )
, m_redimensionnable       ( true )
, m_fermable               ( true )

, m_dragging        ( false )
, m_redimDroite     ( false )
, m_redimGauche     ( false )
, m_redimBas        ( false )
, m_redimHaut       ( false )
{
    initUI();
}


/////////////////////////////////////////////////
Fenetre::Fenetre(   sf::RenderWindow *  fenetre
                ,   sf::Vector2f        taille
                ,   bool                depl
                ,   bool                ferm
                ,   bool                redim    )
: m_fenetreSFML     ( fenetre )
, m_bordure         ( 7 )
, m_taille          ( taille )
, m_skinBtn         ( new Skin() )

, m_deplacable             ( depl )
, m_redimensionnable       ( redim )
, m_fermable               ( ferm )

, m_dragging        ( false )
, m_redimDroite     ( false )
, m_redimGauche     ( false )
, m_redimBas        ( false )
, m_redimHaut       ( false )
{
    initUI();


}

/////////////////////////////////////////////////
Fenetre::~Fenetre()
{

}

/////////////////////////////////////////////////
void
Fenetre::initUI()
{


    // le fond
    m_fond = std::shared_ptr<Image>   ( new Image    ( ) );


    // création des gadgets pour l'interface de la fenêtre
    m_grpUI                 = std::shared_ptr<Groupe>  ( new Groupe   (  ) );
    m_grpUI->setParent ( this );

    m_lblTitre              = std::shared_ptr<Label>   ( new Label    ( "Fenêtre" , m_skin->fenetre ) );
    m_grpUI->ajouter ( m_lblTitre );
//    m_lblFermer             = std::shared_ptr<Label>   ( new Label    ( "X"       , m_skin->fenetre ) );

    if ( m_fermable )  {
        m_btnFermer             = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnFermer->setIcone ( icoMngr.acceder( Icone::Fermer ) );
        m_grpUI->ajouter ( m_btnFermer );
        initUI_fermer();
    }


    if ( m_deplacable )  {
        m_btnDrag               = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_grpUI->ajouter ( m_btnDrag );
        initUI_drag();
    }

    if ( m_redimensionnable )  {
        m_btnRedimBasDroite     = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimBasGauche     = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimHautDroite    = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimHautGauche    = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimGauche        = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimDroite        = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimBas           = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );
        m_btnRedimHaut          = std::shared_ptr<Bouton>  ( new Bouton   ( m_skin ) );

        // integration dans le groupe UI

     //   m_grpUI->ajouter ( m_lblFermer );
    //    ajouter ( m_grpUI );

        m_grpUI->ajouter ( m_btnRedimBasDroite );
        m_grpUI->ajouter ( m_btnRedimBasGauche );
        m_grpUI->ajouter ( m_btnRedimHautDroite );
        m_grpUI->ajouter ( m_btnRedimHautGauche );
        m_grpUI->ajouter ( m_btnRedimGauche );
        m_grpUI->ajouter ( m_btnRedimDroite );
        m_grpUI->ajouter ( m_btnRedimBas );
        m_grpUI->ajouter ( m_btnRedimHaut );

        initUI_redim();
    }


    // le cadre autour du group contenant
    m_CadreContenu          = std::shared_ptr<Image>   ( new Image    ( ) );

    std::cout << "--------------------------------------------------------------------\n";
    // groupe d'affichage, le contenu des élements de la fenêtre
    m_contenant  = std::shared_ptr<Contenant>  ( new Contenant   ( m_fenetreSFML ) );
    m_contenant->setParent (this);

    // initialiser le skin pour les boutons de l'ui de la fenetre ( genre les boutons drag, redim ... )
    initSkinBouton ();
    updateStyle();


    // actualiser les geometries
    majGeom ();


    // Declenchement de l'évenement d'ouverture de la fenetre;
    declencher ( Evenements::onFen_Ouvre );


   // initBoutonsActifs();


}



/////////////////////////////////////////////////
void
Fenetre::initBoutonsActifs()
{
    /*
    m_btnFermer->setVisible             ( m_fermable );
    m_btnDrag->setVisible               ( m_deplacable );
    m_btnRedimBasDroite->setVisible     ( m_redimensionnable );
    m_btnRedimBasGauche->setVisible     ( m_redimensionnable );
    m_btnRedimHautDroite->setVisible    ( m_redimensionnable );
    m_btnRedimHautGauche->setVisible    ( m_redimensionnable );
    m_btnRedimGauche->setVisible        ( m_redimensionnable );
    m_btnRedimDroite->setVisible        ( m_redimensionnable );
    m_btnRedimBas->setVisible           ( m_redimensionnable );
    m_btnRedimHaut->setVisible          ( m_redimensionnable );


    m_btnFermer->setActif               ( m_fermable );
    m_btnDrag->setActif                 ( m_deplacable );
    m_btnRedimBasDroite->setActif       ( m_redimensionnable );
    m_btnRedimBasGauche->setActif       ( m_redimensionnable );
    m_btnRedimHautDroite->setActif      ( m_redimensionnable );
    m_btnRedimHautGauche->setActif      ( m_redimensionnable );
    m_btnRedimGauche->setActif          ( m_redimensionnable );
    m_btnRedimDroite->setActif          ( m_redimensionnable );
    m_btnRedimBas->setActif             ( m_redimensionnable );
    m_btnRedimHaut->setActif            ( m_redimensionnable );
    */
}

/////////////////////////////////////////////////
void
Fenetre::initUI_drag()
{

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
    // fonctions
    m_fctFermer   =[this](){
        supprimer();
        declencher ( Evenements::onFen_Ferme );
    };
    m_fctFermerEntre = [this](){
       // m_lblFermer->setColor( m_skin->fenetre->txt_couleur );
    };
    m_fctFermerSort = [this](){
      //  m_lblFermer->setColor( m_skin->fenetre->txt_couleur );
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
Fenetre::setSkin ( std::shared_ptr<Skin>    skin )
{
    m_skin = skin ;
    initSkinBouton ();
    updateStyle();
};


/////////////////////////////////////////////////
void
Fenetre::initSkinBouton (){

    m_skinBtn =   std::make_shared<gui::Skin> () ;

    sf::Color transparent =  sf::Color  ( 255,255,255 , 255 );

    //// BOUTON REPOS ///////////////////////////////////
    m_skinBtn->btnRepos->txt_style         = sf::Text::Style::Regular ;
    m_skinBtn->btnRepos->txt_taille        = m_skin->btnRepos->txt_taille;
    m_skinBtn->btnRepos->txt_couleur       = transparent;
    m_skinBtn->btnRepos->lgn_epaisseur     = 0;
    m_skinBtn->btnRepos->lgn_couleur       = transparent;
    m_skinBtn->btnRepos->fnd_couleur       = sf::Color  ( 255,255,255 , 0 );
    m_skinBtn->btnRepos->fnd_texture       = sf::Texture ();
    m_skinBtn->btnRepos->align             = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnRepos->ajust             = gui::Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    m_skinBtn->btnSurvol->txt_style        = sf::Text::Style::Regular;
    m_skinBtn->btnSurvol->txt_taille       = m_skin->btnSurvol->txt_taille;
    m_skinBtn->btnSurvol->txt_couleur      = transparent;
    m_skinBtn->btnSurvol->lgn_epaisseur    = 0;
    m_skinBtn->btnSurvol->lgn_couleur      = transparent;
    m_skinBtn->btnSurvol->fnd_couleur      = sf::Color  ( 255,255,255 , 20 );
    m_skinBtn->btnSurvol->fnd_texture      = sf::Texture ();
    m_skinBtn->btnSurvol->align            = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnSurvol->ajust            = gui::Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    m_skinBtn->btnPress->txt_style         = sf::Text::Style::Regular;
    m_skinBtn->btnPress->txt_taille        = m_skin->btnPress->txt_taille;
    m_skinBtn->btnPress->txt_couleur       = transparent;
    m_skinBtn->btnPress->lgn_epaisseur     = 0;
    m_skinBtn->btnPress->lgn_couleur       = transparent;
    m_skinBtn->btnPress->fnd_couleur       = sf::Color  ( 255,255,255 , 40 );
    m_skinBtn->btnPress->fnd_texture       = sf::Texture ();
    m_skinBtn->btnPress->align             = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnPress->ajust             = gui::Ajustements::Sans;

}


/////////////////////////////////////////////////
void
Fenetre::updateStyle( ){

    if ( m_deplacable )
        m_btnDrag->setSkin              ( m_skinBtn ) ;

    if ( m_fermable )
        m_btnFermer->setSkin            ( m_skinBtn ) ;

    if ( m_redimensionnable )  {
        m_btnRedimBasDroite->setSkin    ( m_skinBtn ) ;
        m_btnRedimBasGauche->setSkin    ( m_skinBtn ) ;
        m_btnRedimHautDroite->setSkin   ( m_skinBtn ) ;
        m_btnRedimHautGauche->setSkin   ( m_skinBtn ) ;
        m_btnRedimDroite->setSkin       ( m_skinBtn ) ;
        m_btnRedimGauche->setSkin       ( m_skinBtn ) ;
        m_btnRedimBas->setSkin          ( m_skinBtn ) ;
        m_btnRedimHaut->setSkin         ( m_skinBtn ) ;
    }

    //// Titre ///////////////////////////////////
    m_lblTitre->setStyle            ( m_skin->fenetre );


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
Fenetre::getLocalBounds ( )  const {
    return  m_fond->getLocalBounds() ;
}


/////////////////////////////////////////////////
sf::FloatRect
Fenetre::getGlobalBounds ( ) const {
    sf::FloatRect result( m_fond->getGlobalBounds() );

    result.left     =  getPosAbs().x - m_bordure;
    result.top      =  getPosAbs().y - ( m_lblTitre->getSize().y +  ( 2 * m_bordure ));

//
//std::cout << "--------------> " ;
//
//   std::cout << "\nresult.left : " << result.left;
//   std::cout << "\nresult.top : " << result.top;
//   std::cout << "\nresult.width : " << result.width;
//   std::cout << "\nresult.height : " << result.height;
//   std::cout << "\n";

    return { result };
}


/////////////////////////////////////////////////
void
Fenetre::setTitre ( std::string titre)            {
    m_lblTitre->setTexte( titre );
    majGeom ();
};


/////////////////////////////////////////////////
std::string
Fenetre::getTitre (  ){
    return m_lblTitre->getTexte();
}




/////////////////////////////////////////////////
void
Fenetre::ajouter( ptr enfant ) {

    m_contenant->ajouter(  enfant );

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
        float minY = m_btnDrag->getSize().y + 4 * m_bordure;
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
    if ( m_redimDroite   or  m_redimBas  or  m_redimGauche or  m_redimHaut) {
        demanderActualisation();
        m_contenant->demanderActualisation();
    }

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
    //      0 ---     |----|-----------------------|----|  ---           ------          //
    //                |Red.|      Redimension      |Red.|  m_bordure        |            //
    //      1 ---     |----|-----------------|-----|----|  ---              |            //
    //                |    |  Titre/drag     |Ferm.|    |  hauteurTitre     |            //
    //                |    |-----------------|-----|    |  ---              |            //
    //                |    |                       |    |  m_bordure        |            //
    //      2 ---     |   0.0----------------------|    |  ---              |   taille.y //
    //                |Red.|                       |Red.|                   |            //
    //                |    |                       |    |                   |            //
    //                |    |      Contenu          |    |                   |            /
    //                |    |      ( taille )       |    |                   |            //
    //                |    |                       |    |                   |            //
    //      3 ---     |----|-----------------------|----|  ---              |            //
    //                |Red.|      Redimemsion      |Red.|  m_bordure        |            //
    //      4 ---     |----|-----------------------|----|  ---          ------           //
    //                                                                                   //
    //                |    |                       |    |                                //
    //               m_bordure                    m_bordure                              //
    //                |---------------------------------|                                //
    //                            m_taille.x                                             //
    //                                                                                   //
    ///////////////////////////////////////////////////////////////////////////////////////
    */


    /////  les repères ///////////////
    float hauteurTitre = m_lblTitre->getSize().y;

//std::cout << "hauteurTitre : "  << hauteurTitre << "\n";
//std::cout << "m_lblTitre : "  << m_lblTitre->getTexte() << "\n";
//std::cout << "m_bordure : "  << m_bordure << "\n";
//std::cout << "m_deplacable : "  << m_deplacable << "\n";

   /* float horiz_0  = - m_bordure ;
    float horiz_1  = 0 ;
    float horiz_2  =  m_taille.x - 2*m_bordure;
    float horiz_4   = m_taille.x - m_bordure;
    float horiz_total = m_taille.x ;

    float verti_0 = - ( hauteurTitre +  (2 * m_bordure ) ) ;
    float verti_1 = - ( hauteurTitre +  m_bordure  ) ;
    float verti_2 = 0 ;
    float verti_3 = m_taille.y - verti_0 - m_bordure;
    float verti_total = m_taille.y ;

    float horiz_3  = horiz_2  - hauteurTitre;*/


    float hauteurBandeauTitre = ( hauteurTitre +  (2 * m_bordure ) );
   // float largeurBandeauTitre = ( hauteurTitre +  (2 * m_bordure ) );


///////////////////////////////////////////////////////////////////////////////////////////////
    m_grpUI->setPosition ( - m_bordure , - hauteurBandeauTitre );
    m_grpUI->setSize ( m_taille );

    //  le fond
    m_fond->setPosition          ( - m_bordure  , - hauteurBandeauTitre );
    m_fond->setSize              ( m_taille   );
    m_CadreContenu->setPosition  ( 0 , 0 );
    m_CadreContenu->setSize      ( { m_taille.x - 2*m_bordure , m_taille.y - hauteurBandeauTitre - m_bordure }    );

    //  le Contenu
    m_contenant->setPosition       ( 0 , 0 );
    m_contenant->setSize           ( m_CadreContenu->getSize() );
//    m_grpContenu->setPosition    ( horiz_1 , verti_2 );



///////////////////////////////////////////////////////////////////////////////////////////////
    //  le bouton drag
    if ( m_deplacable ) {
        m_btnDrag->setPosition   ( { m_bordure , m_bordure } );
        if ( m_fermable )
            m_btnDrag->setSize   ( { m_taille.x -  3 * m_bordure - hauteurTitre , hauteurTitre + m_bordure } );
        else
            m_btnDrag->setSize   ( { m_taille.x -  2 * m_bordure , hauteurTitre + m_bordure } );
    }

    //  les boutons redimmensionnement
    if ( m_redimensionnable ) {

        // les coins
        m_btnRedimBasGauche->setSize        ( { m_bordure   , m_bordure } );
        m_btnRedimBasGauche->setPosition    ( { 0           , m_taille.y - m_bordure } );
        m_btnRedimBasDroite->setSize        ( { m_bordure   , m_bordure } );
        m_btnRedimBasDroite->setPosition    ( { m_taille.x - m_bordure     , m_taille.y - m_bordure } );
        m_btnRedimHautGauche->setSize       ( { m_bordure   , m_bordure } );
        m_btnRedimHautGauche->setPosition   ( { 0     , 0 } );
        m_btnRedimHautDroite->setSize       ( { m_bordure   , m_bordure } );
        m_btnRedimHautDroite->setPosition   ( { m_taille.x - m_bordure      , 0 } );

        // les arretes
        m_btnRedimGauche->setSize           ( { m_bordure                   , m_taille.y - 2* m_bordure } );
        m_btnRedimGauche->setPosition       ( { 0                           , m_bordure                 } );
        m_btnRedimDroite->setSize           ( { m_bordure                   , m_taille.y - 2* m_bordure } );
        m_btnRedimDroite->setPosition       ( { m_taille.x - m_bordure      ,  m_bordure                } );
        m_btnRedimBas->setSize              ( { m_taille.x - 2*m_bordure    , m_bordure                 } );
        m_btnRedimBas->setPosition          ( { m_bordure                   , m_taille.y - m_bordure    } );
        m_btnRedimHaut->setSize             ( { m_taille.x -2*m_bordure     , m_bordure                 } );
        m_btnRedimHaut->setPosition         ( { m_bordure                   , 0                         } );

    }

    //  le titre
   // m_lblTitre->aligner ( *m_btnDrag , Alignements::Ctre_Gche );
        m_lblTitre->setPosition ( m_bordure , m_bordure );



    //  le bouton fermer
    if ( m_fermable ) {
        m_btnFermer->setSize      ( { hauteurTitre + m_bordure ,  hauteurTitre + m_bordure } );
        m_btnFermer->setPosition  ( { m_taille.x - hauteurTitre - 2*m_bordure , m_bordure } );
//        m_lblFermer->aligner      ( *m_btnFermer  , Alignements::Ctre_Mili );
   //     m_lblFermer->setPosition  ( { m_lblFermer->getPosition().x , m_lblTitre->getPosition().y } );
    }
    updateStyle( );
}


/////////////////////////////////////////////////
void
Fenetre::traiter_evenements ( const sf::Event& event ) {
    m_grpUI->traiter_evenements( event );
    m_contenant->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}



/////////////////////////////////////////////////
void
Fenetre::actualiser ( float deltaT )    {


/*
std::cout << "---------------------------------------------------------\n";
std::cout << "m_contenant->getContenuBounds().left : " << m_contenant->getContenuBounds().left << "\n";
std::cout << "m_contenant->getContenuBounds().top : " << m_contenant->getContenuBounds().top << "\n";
std::cout << "m_contenant->getContenuBounds().width : " << m_contenant->getContenuBounds().width << "\n";
std::cout << "m_contenant->getContenuBounds().height : " << m_contenant->getContenuBounds().height << "\n";


*/



    // > Drag et redimensionnements
    ManipulerFenetre ();


    // > Actualiser le contenu de la fenetre
    m_contenant->actualiser    ( deltaT );

    // mise a jour des boutons de l'interface
    m_grpUI->actualiser    ( deltaT );


    if ( not m_aActualiser ) return;

    // mise a jour des geometries
    majGeom ();


    m_aActualiser = false;
}


/////////////////////////////////////////////////
void
Fenetre::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    if ( not m_visible ) return;


    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();

    target.draw      ( *m_fond , states );

    target.draw      ( *m_contenant , states );

    target.draw      ( *m_grpUI , states );



//    // dessiner les éléments de l'UI de la fenetre
//    for ( ptr enfant : m_enfants )
//        target.draw      ( *enfant , states );
//
//    // la texture dans laquelle on va dessiner les éléments contenus
//    sf::RenderTexture       texture;
//    if ( texture.create   ( m_taille.x , m_taille.y ) ) {
//
//        //dessin du contenu dans la texture
//        texture.clear     ( m_skin->invisible->fnd_couleur );
//        texture.draw      ( *m_grpContenu );
//        texture.display   ( );
//
//        //Appliquer la texture au sprite qui va l'afficher.
//        m_contenu->setTexture    ( texture.getTexture() );
//        m_contenu->setTextureRect( sf::IntRect(0, 0, m_taille.x , m_taille.y  ) );
//    }

    //dessiner le sprite dans la fenêtre.
  //  target.draw      ( *m_contenu , states );

}


} // fin namespace
















