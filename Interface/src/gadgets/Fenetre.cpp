
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

/////////////////////////////////////////////////
Fenetre::Fenetre(   sf::RenderWindow  *     fenetre
                ,   std::shared_ptr<Skin>   skin
                ,   sf::Vector2f            taille  )
: Gadget            ( )
, m_fenetreSFML     ( fenetre )
, m_bordure         ( 7 )
, m_taille          ( taille )
{

    std::cout << "Fenetre::Fenetre()\n";
    creerUI();
    declencher ( Evenements::onFen_Ouvre );
}

/////////////////////////////////////////////////
Fenetre::~Fenetre()
{

}



/////////////////////////////////////////////////
void
Fenetre::creerUI()
{
    m_UI->setParent ( this);


    std::cout << "Fenetre::creerUI(0)\n";
    // Creation des éléments
    m_fond          = std::shared_ptr<Image>        ( new Image    ( ) );
    m_CadreContenu  = std::shared_ptr<Image>        ( new Image    ( ) );
 //   m_grpContenu    = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_spriteContenant = std::shared_ptr<sf::Sprite>   ( new sf::Sprite   ( ) );

    std::cout << "Fenetre::creerUI(1)\n";
    // heritage des éléments de l'UI vis à vis de la fenêtre
 //   m_grpContenu->setParent (this);
    m_UI->ajouter   ( m_fond );
    m_UI->ajouter   ( m_CadreContenu );

    std::cout << "Fenetre::creerUI(2)\n";
    // mise a jour des styles pour l'ui
    updateStyle();

    std::cout << "Fenetre::creerUI(3)\n";
    // Mise à jour des gemoetries
    majGeom ();

    std::cout << "Fenetre::creerUI(4)\n";
}




/////////////////////////////////////////////////
void
Fenetre::updateStyle( ){

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

    result.left     =  getPosAbs().x;// - m_bordure;
    result.top      =  getPosAbs().y;// - m_bordure;

    return { result };
}


/*

/////////////////////////////////////////////////
void
Fenetre::ajouter( ptr enfant ) {

    m_grpContenu->ajouter(  enfant );

    majGeom ();
};*/




/////////////////////////////////////////////////
void
Fenetre::majGeom ()    {

    updateStyle( );

    /*
    // ///// Position des reperes dans la fenetre ///////////////////////////////////
    //                                                                             //
    //                                                                             //
    //                HORIZ_...                                                    //
    //                                                                             //
    //  VERTI_...     0    1                       2    3                          //
    //                |    |                       |    |                          //
    //      0 ---     |----|-----------------------|----|  ---        ---          //
    //                |    |                       |    |  m_bordure   |           //
    //      1 ---     |----|-----------------------|----|  ---         |           //
    //                |    | 0,0                   |    |              |           //
    //                |    |                       |    |              |           //
    //                |    |                       |    |              |           //
    //                |    |      Contenu          |    |              | taille.y  //
    //                |    |                       |    |              |           //
    //                |    |                       |    |              |           //
    //                |    |                       |    |              |           //
    //      2 ---     |----|-----------------------|----|  ---         |           //
    //                |    |                       |    |  m_bordure   |           //
    //      3 ---     |----|-----------------------|----|  ---        ---          //
    //                                                                             //
    //                |    |                       |    |                          //
    //               m_bordure                    m_bordure                        //
    //                |---------------------------------|                          //
    //                              taille.x                                       //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////
    */


    /////  les repères ///////////////

    float horiz_0  = - m_bordure ;
    float horiz_1  = 0 ;
    float horiz_2  =  m_taille.x - m_bordure ;
    //float horiz_3  =  horiz_2 + m_bordure;
    float horiz_total   = m_taille.x  ;

    float verti_0       = - m_bordure ;
    float verti_1       = 0 ;
    float verti_2       = m_taille.y  - m_bordure  ;
    //float verti_3       = verti_2 + m_bordure  ;

    float verti_total   = m_taille.y  ;

    // la taille de notre contenu
    m_tailleContenu = { m_taille.x - 2*m_bordure  ,   m_taille.y - 2*m_bordure };

    // l'origine de la fenetre
    //setOrigin( horiz_0  , verti_0 );



    //  le fond
    m_fond->setPosition          ( horiz_0 , verti_0 );
    m_fond->setSize              ( { horiz_total , verti_total  }    );

    m_CadreContenu->setPosition  ( horiz_1 , verti_1 );
    m_CadreContenu->setSize      ( m_tailleContenu    );

    //  le Contenu
    //  m_spriteContenant->setSize           ( m_CadreContenu->getSize () );
    m_spriteContenant->setPosition       ( horiz_1 , verti_1 );
 //   m_grpContenu->setSize        ( m_tailleContenu );
 //   m_grpContenu->setPosition    ( horiz_1 , verti_1 );

    updateStyle( );
}


/////////////////////////////////////////////////
void
Fenetre::traiter_evenements ( const sf::Event& event ) {

    m_UI->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}



/////////////////////////////////////////////////
void
Fenetre::actualiser ( float deltaT )    {

    // > Actualiser niveau Gadget
    Gadget::actualiser          ( deltaT );

    // > Actualiser le contenu de la fenetre
    m_UI->actualiser    ( deltaT );
}


/////////////////////////////////////////////////
void
Fenetre::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();

    // dessiner les éléments de l'UI de la fenetre
    //dessinerUI ( target , states );
    target.draw      ( *m_UI , states );

//    for ( ptr ui : m_UI )
//        target.draw      ( *ui , states );

    // la texture dans laquelle on va dessiner les éléments contenus
    sf::RenderTexture       texture;
    if ( texture.create   ( m_tailleContenu.x , m_tailleContenu.y ) ) {

        //dessin du contenu dans la texture
        texture.clear     ( m_skin->invisible->fnd_couleur );
        //texture.draw      ( *m_grpContenu );
        for ( ptr enfant : m_enfants )
            texture.draw      ( *enfant );


        texture.display   ( );

        //Appliquer la texture au sprite qui va l'afficher.
        m_spriteContenant->setTexture    ( texture.getTexture() );
        m_spriteContenant->setTextureRect( sf::IntRect(0, 0, m_tailleContenu.x , m_tailleContenu.y  ) );
    }

    //dessiner le sprite du contenu dans la fenêtre.
    target.draw      ( *m_spriteContenant , states );

}


}
















