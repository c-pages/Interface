
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gadgets/Label.h"

namespace gui {

/////////////////////////////////////////////////
Label::Label    ( std::string   texte )
: Gadget    ( )
, m_texte   ( new sf::Text( ) )
{
//    std::cout << "  --- Label --- Label ---\n";
    m_texte->setString  ( texte );
    majGeom         ( );
}


/////////////////////////////////////////////////
Label::Label    ( std::string   texte
                , std::shared_ptr<Style>    style )
: Gadget    ( style )
, m_texte   ( new sf::Text () )
{
//    std::cout << "  --- Label --- Label ---\n";
    m_texte->setString  ( texte );
    majGeom( ) ;
}


/////////////////////////////////////////////////
Label::~Label()
{ }


/////////////////////////////////////////////////
sf::FloatRect
Label::getLocalBounds ( )const {
    //m_texte->getLocalBounds()
    sf::FloatRect  result = m_texte->getLocalBounds();

    result.left     =  getPosition().x;
    result.top      =  getPosition().y;

    result.width    +=  m_texte->getLocalBounds().left;
    result.top      +=  m_texte->getLocalBounds().top;
//std::cout << "--------------> Y : " << getPosition().y << "\n";
    return result;
}


/////////////////////////////////////////////////
sf::FloatRect
Label::getGlobalBounds ( ) const{
    sf::FloatRect  result = m_texte->getGlobalBounds();

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;
    return  result ;
}


/////////////////////////////////////////////////
sf::Vector2f
Label::getSize( )  const  {
    return sf::Vector2f  (   getLocalBounds().width , getLocalBounds().height );
};


/////////////////////////////////////////////////
void
Label::majGeom( )    {
    m_texte->setFont             ( m_style->txt_police );
    m_texte->setStyle            ( m_style->txt_style );
    m_texte->setCharacterSize    ( m_style->txt_taille );
    m_texte->setColor            ( m_style->txt_couleur);
}


/////////////////////////////////////////////////
void
Label::traiter_evenements ( const sf::Event& event )    {
    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );
}


////////////////////////////////////////////////
void
Label::actualiser ( float deltaT )    {
    Gadget::actualiser (deltaT);
}


/////////////////////////////////////////////////
void
Label::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {
    states.transform *= getTransform();
    target.draw      ( *m_texte , states );

    for ( ptr enfant : m_enfants )
        target.draw      ( *enfant , states );
}

} // fin namespace gui
