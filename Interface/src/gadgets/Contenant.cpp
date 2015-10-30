


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/Contenant.h"
#include "gadgets/Groupe.h"

namespace gui {

/////////////////////////////////////////////////
Contenant::Contenant( sf::RenderWindow  *     fenetre )
: Gadget()
, m_fenetreSFML     ( fenetre )
, m_bSliderVerti    ( false )
, m_bSliderHori     ( false )
, m_fond            ( new Image () )
, m_grpContenu      ( new Groupe () )
, m_spriteContenant ( new sf::Sprite ())
, m_posContenu      ( 0 , 0 )
, m_slideVerti      ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Verticale , m_skin) )
, m_slideHori       ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Horizontale, m_skin ) )
{
    m_UI->setParent (this );
    //ctor
    m_UI->ajouter ( m_slideVerti );
    m_UI->ajouter ( m_slideHori );

}

/////////////////////////////////////////////////
Contenant::~Contenant()
{
    //dtor
}




/////////////////////////////////////////////////
sf::FloatRect
Contenant::getLocalBounds ( )const {
    sf::FloatRect result( m_fond->getLocalBounds() );

    result.left     =  getPosition().x;
    result.top      =  getPosition().y;
    result.width    =  m_taille.x;
    result.height   =  m_taille.y;

    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
Contenant::getGlobalBounds ( )const {
    sf::FloatRect result( m_fond->getLocalBounds() );

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;
    result.width    =  m_taille.x;
    result.height   =  m_taille.y;

    return { result };
}

/////////////////////////////////////////////////
sf::FloatRect
Contenant::getContenuBounds ( ) const {

    sf::FloatRect result ( 0,0,0,0 );

    for ( ptr enfant : m_enfants ) {
        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
        if ( result.width < rect.left + rect.width )  result.width  = rect.left + rect.width;
        if ( result.height < rect.top + rect.height ) result.height = rect.top + rect.height;
    }

    result.width += 10;
    result.height += 10;

    return { result };
}



/////////////////////////////////////////////////
void
Contenant::traiter_evenements ( const sf::Event& event ) {

    m_UI->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}



/////////////////////////////////////////////////
void
Contenant::actualiser ( float deltaT )    {

    m_UI->actualiser( deltaT );
    m_UI->setSize (m_taille);


    // on regarde si on a besoin d'un slider horizontal
    if ( getContenuBounds().width > m_taille.x )
        m_bSliderHori = true;
    else
        m_bSliderHori = false;

    // on regarde si on a besoin d'un slider vertical
    if ( getContenuBounds().height > m_taille.y )
        m_bSliderVerti = true;
    else
        m_bSliderVerti = false;

//std::cout << "->getContenuBounds().width : " << getContenuBounds().width  <<"\n";
//std::cout << "->m_taille().x : " << m_taille.x  <<"\n";

    // on positionne les sliders
    if ( m_bSliderHori and m_bSliderVerti ) {
        m_slideHori->setLongueurMax         ( m_taille.x - m_slideVerti->getSize().x );
        m_slideVerti->setLongueurMax        ( m_taille.y - m_slideHori->getSize().y );
        m_slideHori->setLongueurCourante    ( m_slideHori->getLongueurMax() / getContenuBounds().width * m_taille.x );
        m_slideVerti->setLongueurCourante   ( m_slideVerti->getLongueurMax() / getContenuBounds().height * m_taille.y );
    }
    else if ( m_bSliderHori ){
        m_slideHori->setLongueurMax         ( m_taille.x );
        m_slideHori->setLongueurCourante    ( m_taille.x / getContenuBounds().width * m_taille.x );
    }
    else if ( m_bSliderVerti ) {
        m_slideVerti->setLongueurMax        ( m_taille.y );
        m_slideVerti->setLongueurCourante   ( m_taille.y / getContenuBounds().height * m_taille.y );
    }
    m_slideHori->setPosition                ( 0 , m_taille.y - m_slideHori->getSize().y  );
    m_slideVerti->setPosition               ( m_taille.x - m_slideVerti->getSize().x , 0 );


m_posContenu.x = m_slideHori->getSlidePos().x  / m_slideHori->getLongueurMax()  * getContenuBounds().width;
m_posContenu.y = m_slideVerti->getSlidePos().y / m_slideVerti->getLongueurMax() * getContenuBounds().height;

//    m_posContenu = {  , m_slideVerti->getSlidePos().y  };



/*
    std::cout << "-----------"
    << "\n  left " << getContenuBounds().left
    << "    top " << getContenuBounds().top
    << "    width " << getContenuBounds().width
    << "    height " << getContenuBounds().height << "" ;

    std::cout << "\n   pos.x " << getPosition().x
    << "    pos.y " << getPosition().y
    << "    taille x " << m_taille.x
    << "    taille y " << m_taille.y << "\n" ;
*/
    // > Actualiser niveau Gadget
    Gadget::actualiser          ( deltaT );

    // > Actualiser le contenu de la fenetre
    //m_UI->actualiser    ( deltaT );
}


/////////////////////////////////////////////////
void
Contenant::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();

    target.draw      ( *m_fond , states );


    // la texture dans laquelle on va dessiner les éléments contenus


    sf::Vector2i    tailleTexture, tailleAffiche;

    tailleTexture.x = getContenuBounds().left   + getContenuBounds().width + 1;
    tailleTexture.y = getContenuBounds().top    + getContenuBounds().height + 1;
    tailleAffiche.x = m_taille.x;
    tailleAffiche.y = m_taille.y;

    if ( m_bSliderHori )    {
        tailleTexture.y -= m_slideHori->getSize().y;
        tailleAffiche.y -= m_slideHori->getSize().y;
    }
    if ( m_bSliderVerti )   {
        tailleTexture.x -= m_slideVerti->getSize().x;
        tailleAffiche.x -= m_slideVerti->getSize().x;
    }



    sf::RenderTexture       texture;
    if ( texture.create   ( tailleTexture.x  , tailleTexture.y   ) ) {

        // dessiner les enfants dans la texture
        texture.clear     ( m_skin->invisible->fnd_couleur );
        for ( ptr enfant : m_enfants )
            texture.draw      ( *enfant );
        texture.display   ( );

        // Appliquer la texture au sprite qui va l'afficher.
        m_spriteContenant->setTexture    ( texture.getTexture() );
        m_spriteContenant->setTextureRect( sf::IntRect( m_posContenu.x , m_posContenu.y , tailleAffiche.x , tailleAffiche.y ) );
    }

    //dessiner le sprite du contenu.
    target.draw      ( *m_spriteContenant , states );

    //target.draw      ( *m_UI , states );
    if ( m_bSliderHori )
        target.draw      ( *m_slideHori , states );

    if ( m_bSliderVerti )
        target.draw      ( *m_slideVerti , states );


}


} // fin namespace








