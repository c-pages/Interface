
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets\Image.h"

namespace gui {

/////////////////////////////////////////////////
Image::Image(  )
: m_rectangle ( new sf::RectangleShape ())
{
//    std::cout << "  --- Image --- Image ---\n";
    Init ();
}


/////////////////////////////////////////////////
Image::Image( std::string  fichier , sf::Vector2f   taille   )
: m_rectangle (new sf::RectangleShape ( taille ))
{
//    std::cout << "  --- Image --- Image ---\n";
    Init ();
}


/////////////////////////////////////////////////
Image::Image( sf::Color couleur , sf::Vector2f  taille  )
: m_rectangle (new sf::RectangleShape ( taille ))
{
//    std::cout << "  --- Image --- Image ---\n";
    Init ();
}


/////////////////////////////////////////////////
Image::~Image()
{

    std::cout << " DESTRUCTEUR Image : " <<  m_enfants.size()    << "\n";

}


/////////////////////////////////////////////////
void
Image::Init (){
    m_texture.setRepeated( true );
}


/////////////////////////////////////////////////
void
Image::setFillColor ( sf::Color color )   {
    m_rectangle->setFillColor   ( color );
}


/////////////////////////////////////////////////
void
Image::setOutlineColor  ( sf::Color color ) {
    m_rectangle->setOutlineColor    ( color );
}


/////////////////////////////////////////////////
void
Image::setOutlineThickness  ( float epaisseur )   {
    m_rectangle->setOutlineThickness    ( epaisseur );
}


/////////////////////////////////////////////////
void
Image::setTexture      ( sf::Texture * newTexture ) {
    m_rectangle->setTexture    ( newTexture );
}


/////////////////////////////////////////////////
void
Image::loadImage      ( std::string fichier  ) {

    if ( not m_image.loadFromFile( fichier ) ) {
        std::cout << "gui::Image :   Erreur de chargement image: \'" << fichier << "\"\n";
    }
    sf::IntRect  tailleTextRect ( 0 , 0 , m_rectangle->getSize().x , m_rectangle->getSize().y );
    m_texture.loadFromImage    ( m_image    );
    m_rectangle->setTexture    ( &m_texture );
    m_rectangle->setTextureRect( tailleTextRect );
}


/////////////////////////////////////////////////
sf::Vector2f
Image::getSize(  )    {
    return m_rectangle->getSize();
    //return sf::Vector2f ( getLocalBounds().width , getLocalBounds().height  ) ;
}


/////////////////////////////////////////////////
void
Image::setSize( sf::Vector2f taille )    {
    m_rectangle->setSize ( taille );
}


/////////////////////////////////////////////////
sf::FloatRect
Image::getLocalBounds( ) {
    return m_rectangle->getLocalBounds();
}


/////////////////////////////////////////////////
sf::FloatRect
Image::getGlobalBounds( ) {
    return m_rectangle->getGlobalBounds();
}


/////////////////////////////////////////////////
void
Image::majGeom ( ) {

    // le cadre
    setOutlineColor        ( m_style->lgn_couleur);
    setOutlineThickness    ( m_style->lgn_epaisseur);

    // le fond
    if ( m_style->aTexture() )
        setTexture( &m_style->fnd_texture );
    else
        setFillColor ( m_style->fnd_couleur );

}

/////////////////////////////////////////////////
void
Image::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {
    states.transform *= getTransform();
    target.draw         ( *m_rectangle , states );
}


} // fin namespace gui


