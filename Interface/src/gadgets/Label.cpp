
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
//, m_fond    ( new sf::RectangleShape ())
{
//    std::cout << "  --- Label --- Label ---\n";
    m_texte->setString  ( texte );
    majGeom         ( );
//    setOrigin       ( m_texte->getGlobalBounds().left ,  m_texte->getGlobalBounds().top );
}


/////////////////////////////////////////////////
Label::Label    ( std::string   texte
                , std::shared_ptr<Style>    style )
: Gadget    ( style )
, m_texte   ( new sf::Text () )
//, m_fond    ( new sf::RectangleShape ())
{

//    std::cout << "  --- Label --- Label ---\n";
    m_texte->setString  ( texte );
    majGeom( ) ;

//    setOrigin( getGlobalBounds().left ,getGlobalBounds().top );

}


/////////////////////////////////////////////////
Label::~Label()
{ }

/*
/////////////////////////////////////////////////
sf::Vector2f
Label::getPosition ( )const {
    //m_texte->getLocalBounds()
    sf::FloatRect  BB = m_texte->getGlobalBounds();
sf::Vector2f result;
    result.x     =  BB.left  - getPosAbs().x;
    result.y     =  BB.top  - getPosAbs().y;

//    result.width    +=  m_texte->getGlobalBounds().left;
//    result.top      +=  m_texte->getGlobalBounds().top;
//std::cout << "--------------> Y : " << getPosition().y << "\n";
    return result;
}*/


/////////////////////////////////////////////////
sf::FloatRect
Label::getLocalBounds ( )const {

/*
    const sf::String str = m_texte->getString() + '\n';

    float maxLineWidth = 0.f;
    float lineWidth = 0.f;
    unsigned int lines = 0;

    for (sf::String::ConstIterator itr = str.begin(); itr != str.end(); ++itr)
    {
        if (*itr == '\n')
        {
            ++lines;
            maxLineWidth = std::max(maxLineWidth, lineWidth);
            lineWidth = 0.f;
        }
        else
        {
            lineWidth += m_texte->getFont()->getGlyph(*itr, m_texte->getCharacterSize(), m_texte->getStyle() & sf::Text::Bold).advance;
        }
    }

    const float lineHeight = static_cast<float>(m_texte->getFont()->getLineSpacing(m_texte->getCharacterSize()));

    sf::FloatRect  result ( getPosition().x, getPosition().y,  maxLineWidth, lines * lineHeight  );

   std::cout << "\nresult.left : "      << result.left;
   std::cout << "\nresult.top : "       << result.top;
   std::cout << "\nresult.width : "     << result.width;
   std::cout << "\nresult.height : "    << result.height;
   std::cout << "\n";

    return result;

*/





    //m_texte->getLocalBounds()
    sf::FloatRect  result = m_texte->getLocalBounds();

    result.left     +=  getPosition().x;
    result.top      +=  getPosition().y;/*
    result.width    -=  m_texte->getLocalBounds().left;
    result.top      -=  m_texte->getLocalBounds().top;*/
/*
    std::string txt = m_texte->getString() ;
std::cout << "--------------> m_texte : " << txt << "\n";

   std::cout << "\nresult.left : " << result.left;
   std::cout << "\nresult.top : " << result.top;
   std::cout << "\nresult.width : " << result.width;
   std::cout << "\nresult.height : " << result.height;
   std::cout << "\n";
*/
    return result;









}


/////////////////////////////////////////////////
sf::FloatRect
Label::getGlobalBounds ( ) const{
    sf::FloatRect  result = m_texte->getGlobalBounds();

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;
    result.width    =   getLocalBounds().width;
    result.height   =   getLocalBounds().height;
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


//m_fond->setSize(sf::Vector2f( getLocalBounds().width,  getLocalBounds().height));
//m_fond->setOutlineColor( sf::Color ( 255,255,255,255));
//m_fond->setOutlineThickness(1);
//m_fond->setFillColor( sf::Color ( 255,255,255,0));
//m_fond->setPosition(getLocalBounds().left - getPosition().x,  getLocalBounds().top - getPosition().y);

//    setOrigin( getGlobalBounds().left ,getGlobalBounds().top );


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
//    target.draw      ( *m_fond , states );

    if ( not m_visible ) return;


    states.transform *= getTransform();

    target.draw ( *m_texte , states );

    for ( ptr enfant : m_enfants )
            target.draw      ( *enfant , states );
}

} // fin namespace gui
