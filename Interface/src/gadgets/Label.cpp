
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>
#include "gadgets\Label.h"
//#include "..\GUI.h"


#include <SFML/Graphics.hpp>

namespace gui {

/////////////////////////////////////////////////
Label::Label    ( std::string     texte )
: Gadget    ( )
, m_texte   ( new sf::Text() )
{
    m_texte->setString  ( texte );
    updateStyle         ( );
}


/////////////////////////////////////////////////
Label::Label    ( std::string   texte
                , Style         style )
: Gadget    ( style )
, m_texte   ( new sf::Text () )
{
    m_texte->setString  ( texte );
    updateStyle();
}


/////////////////////////////////////////////////
Label::~Label()
{ }


/////////////////////////////////////////////////
sf::FloatRect
Label::getLocalBounds ( ) {
    //m_texte->getLocalBounds()
    return m_texte->getLocalBounds();
}


/////////////////////////////////////////////////
sf::FloatRect
Label::getGlobalBounds ( ) {
    sf::FloatRect  result = m_texte->getGlobalBounds();

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;
    return  result ;
}


/////////////////////////////////////////////////
sf::Vector2f
Label::getSize( )    {
    return sf::Vector2f  (   getLocalBounds().width , getLocalBounds().height );
};


/////////////////////////////////////////////////
void
Label::updateStyle( )    {
    m_texte->setFont             ( m_style.txt_police );
    m_texte->setStyle            ( m_style.txt_style );
    m_texte->setCharacterSize    ( m_style.txt_taille );
    m_texte->setColor            ( m_style.txt_couleur);
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
    target.draw      ( *this->m_texte , states );

    for ( ptr enfant : m_enfants )
        target.draw      ( *enfant , states );
}

} // fin namespace gui
