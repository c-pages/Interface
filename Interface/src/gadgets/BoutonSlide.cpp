
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "BoutonSlide.h"
#include <iostream>

namespace gui
{

/////////////////////////////////////////////////
BoutonSlide::BoutonSlide    (   sf::RenderWindow *    fenetre
                            ,   Orientation             orient
                            ,   std::shared_ptr<Skin>   skin
                            ,   float                   longueur )
: m_orientation     ( orient )
, m_fenetreSFML     ( fenetre )
, m_longueurMax     ( longueur )
, m_drag            ( false )
, m_directDrag      ( false )
, m_largeur         ( 7 )
{
    creerUI();
    majGeom();
}


/////////////////////////////////////////////////
BoutonSlide::~BoutonSlide()
{
    //dtor
}

/////////////////////////////////////////////////
sf::FloatRect
BoutonSlide::getLocalBounds ( ) const {
    sf::FloatRect result( m_btnFond->getLocalBounds() );

    result.left     =  getPosition().x;
    result.top      =  getPosition().y;

    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
BoutonSlide::getGlobalBounds ( ) const {
    sf::FloatRect result( m_btnFond->getLocalBounds() );

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;

    return { result };
}
/////////////////////////////////////////////////
void
BoutonSlide::creerUI()
{



    // les fonctions de drag
    m_fctDrag_Debut = [this](){
        m_drag          = true;
        m_posBtnOrig    = m_btnSlide->getPosition();
        m_posMouseOrig  = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
    };
    m_fctDrag_Fin = [this](){
        m_drag  = false;
    };
    m_fctDrag_direct = [this](){


        m_directDrag          = true;

        m_posBtnOrig    = m_btnSlide->getPosition();
        m_posMouseOrig  = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;



        sf::Vector2f  mouseRelativePos   = m_posMouseOrig - getPosAbs();

        sf::Vector2f  slideRelativePos   = m_btnSlide->getPosition();


        std::cout << "mouseRelativePos : " << mouseRelativePos.x << " " << mouseRelativePos.y << "\n";

        std::cout << "slideRelativePos : " << slideRelativePos.x << " " << slideRelativePos.y << "\n";
        //
        //

        int decalage = 20;
        if ( m_orientation == Orientation::Horizontale)
        {
            if ( mouseRelativePos.x > slideRelativePos.x )
                m_btnSlide->move ( decalage , 0 );
            else
                m_btnSlide->move ( -decalage , 0 );
//            m_btnSlide->setPosition (     {   m_posBtnOrig.x +  mousePos.x - m_posMouseOrig.x , 0 } ) ;
        }
        if ( m_orientation == Orientation::Verticale)
        {
            if ( mouseRelativePos.y > slideRelativePos.y )
                m_btnSlide->move ( 0 , decalage  );
            else
                m_btnSlide->move ( 0 , -decalage );
        }
//


//
//        if ( m_orientation == Orientation::Horizontale)
//            m_btnSlide->setPosition (     {   m_posBtnOrig.x +  mousePos.x - m_posMouseOrig.x , 0 } ) ;
//        if ( m_orientation == Orientation::Verticale)
//            m_btnSlide->setPosition (     {  0,  m_posBtnOrig.y +  m_posMouseOrig.y } ) ;
//


//        //m_drag  = false;
//        m_posMouseOrig  = sf::Vector2f   (sf::Mouse::getPosition( *m_fenetreSFML )) ;
//        m_btnSlide->setPosition ( m_posMouseOrig ) ;
        m_aActualiser = true;
        majGeom();

       // m_parent->demanderActualisation();
    };



    initSkin();

    m_btnFond    = std::shared_ptr<Bouton> ( new Bouton ( m_skinBtnFond ) );
    m_btnSlide   = std::shared_ptr<Bouton> ( new Bouton (  ) );

  //  m_btnSlide->setSize (  { m_largeur ,m_largeur } );
    m_btnSlide->lier    ( Evenements::onBtnG_Press          , m_fctDrag_Debut );
    m_btnSlide->lier    ( Evenements::onBtnG_Relache        , m_fctDrag_Fin );
    m_btnSlide->lier    ( Evenements::onBtnG_RelacheDehors  , m_fctDrag_Fin );
    m_btnFond->lier     ( Evenements::onBtnG_Relache        , m_fctDrag_direct );


    ajouter ( m_btnFond );
    m_btnSlide->lier ( Evenements::onBtnD_Press         , [this](){std::cout << "POPOPOPO\n";} );
    ajouter ( m_btnSlide );
    //dtor
}

/////////////////////////////////////////////////
void
BoutonSlide::initSkin (){

    m_skinBtnFond =   std::make_shared<gui::Skin> () ;

    sf::Color transparent =  sf::Color  ( 255,255,255 , 0 );

    //// BOUTON REPOS ///////////////////////////////////
    m_skinBtnFond->btnRepos->txt_style         = sf::Text::Style::Regular ;
    m_skinBtnFond->btnRepos->txt_taille        = 10;
    m_skinBtnFond->btnRepos->txt_couleur       = transparent;
    m_skinBtnFond->btnRepos->lgn_epaisseur     = 0;
    m_skinBtnFond->btnRepos->lgn_couleur       = transparent;
    m_skinBtnFond->btnRepos->fnd_couleur       = transparent;
    m_skinBtnFond->btnRepos->fnd_texture       = sf::Texture ();
    m_skinBtnFond->btnRepos->align             = gui::Alignements::Libre;
    m_skinBtnFond->btnRepos->ajust             = gui::Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    m_skinBtnFond->btnSurvol->txt_style        = sf::Text::Style::Regular;
    m_skinBtnFond->btnSurvol->txt_taille       = 10;
    m_skinBtnFond->btnSurvol->txt_couleur      = transparent;
    m_skinBtnFond->btnSurvol->lgn_epaisseur    = 0;
    m_skinBtnFond->btnSurvol->lgn_couleur      = transparent;
    m_skinBtnFond->btnSurvol->fnd_couleur      = transparent;
    m_skinBtnFond->btnSurvol->fnd_texture      = sf::Texture ();
    m_skinBtnFond->btnSurvol->align            = gui::Alignements::Libre;
    m_skinBtnFond->btnSurvol->ajust            = gui::Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    m_skinBtnFond->btnPress->txt_style         = sf::Text::Style::Regular;
    m_skinBtnFond->btnPress->txt_taille        = 10;
    m_skinBtnFond->btnPress->txt_couleur       = transparent;
    m_skinBtnFond->btnPress->lgn_epaisseur     = 0;
    m_skinBtnFond->btnPress->lgn_couleur       = transparent;
    m_skinBtnFond->btnPress->fnd_couleur       = transparent;
    m_skinBtnFond->btnPress->fnd_texture       = sf::Texture ();
    m_skinBtnFond->btnPress->align             = gui::Alignements::Libre;
    m_skinBtnFond->btnPress->ajust             = gui::Ajustements::Sans;

}
/////////////////////////////////////////////////
void
BoutonSlide::majGeom()
{
    if ( not m_aActualiser ) return;

    // dimensionnements
    switch ( m_orientation ){
        case Orientation::Verticale: {
            m_btnFond->setSize ( { m_largeur , m_longueurMax } );
            m_btnSlide->setSize ( { m_largeur , m_longueurCourant});
        } break;
        case Orientation::Horizontale: {
            m_btnFond->setSize ( { m_longueurMax , m_largeur } );
            m_btnSlide->setSize ( { m_longueurCourant , m_largeur } );
        } break;
    }

    // position
    sf::Vector2f    pos = m_btnSlide->getPosition();

    // contraintes de position
    if (pos.x<0) pos.x = 0;
    if (pos.y<0) pos.y = 0;
    if (pos.x>m_longueurMax - m_btnSlide->getSize().x ) pos.x = m_longueurMax - m_btnSlide->getSize().x ;
    if (pos.y>m_longueurMax - m_btnSlide->getSize().y ) pos.y = m_longueurMax - m_btnSlide->getSize().y ;

    m_btnSlide->setPosition     (  pos  );

}




/////////////////////////////////////////////////
void
BoutonSlide::traiter_evenements ( const sf::Event& event )
{
   //UI::traiter_evenements( event );
    Gadget::traiter_evenements( event );
}


/////////////////////////////////////////////////
void
BoutonSlide::actualiser ( float deltaT )
{



    // > Actualiser le Drag
    if ( m_drag ) {
        sf::Vector2f    mousePos = sf::Vector2f   ( sf::Mouse::getPosition( *m_fenetreSFML ) ) ;
        sf::Vector2f    pos ;


        if ( m_orientation == Orientation::Horizontale)
            pos =     {   m_posBtnOrig.x +  mousePos.x - m_posMouseOrig.x , 0 };
        if ( m_orientation == Orientation::Verticale)
            pos =      {  0,  m_posBtnOrig.y +  mousePos.y - m_posMouseOrig.y };

        m_btnSlide->setPosition     (  pos  );
        m_aActualiser = true;
    }

    m_directDrag = false;


    //UI::actualiser( deltaT );
    Gadget::actualiser( deltaT );
}

/////////////////////////////////////////////////
void
BoutonSlide::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{

    if ( not estVisible() ) return;


   // Bouton::draw    ( target, states );

    states.transform *= getTransform();

    target.draw     ( *m_btnFond , states );
    target.draw     ( *m_btnSlide , states );

}


}   // fin namespace
