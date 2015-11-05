/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/Infos.h>
#include <gadgets/Label.h>
#include <Utilitaires.h>

namespace gui
{

///////////////////////////////////////////////////
Infos::Infos( )
: m_lblMouseX   ( new Label())
, m_lblMouseY   ( new Label())
, m_lblMouseFps ( new Label())
, m_clock       ()
, m_compteurFPS (0)
, m_FPS         (0)
{
    m_clock.restart();

    m_lblMouseX->setStyle ( m_skin->lblLog );
    m_lblMouseY->setStyle ( m_skin->lblLog );
    m_lblMouseFps->setStyle ( m_skin->lblLog );

    m_lblMouseX->setPosition    ( 0,0 );
    m_lblMouseY->setPosition    ( 50,0 );
    m_lblMouseFps->setPosition  ( 100,0 );


}


///////////////////////////////////////////////////
Infos::Infos( std::shared_ptr <Skin>    skin )
: m_lblMouseX   ( new Label())
, m_lblMouseY   ( new Label())
, m_lblMouseFps ( new Label())
, m_clock       ()
, m_compteurFPS (0)
, m_FPS         (0)
{
    m_clock.restart();

    m_skin = skin ;

    m_lblMouseX->setStyle ( m_skin->lblLog );
    m_lblMouseY->setStyle ( m_skin->lblLog );
    m_lblMouseFps->setStyle ( m_skin->lblLog );

    m_lblMouseX->setPosition    ( 0,0 );
    m_lblMouseY->setPosition    ( 50,0 );
    m_lblMouseFps->setPosition  ( 100,0 );
}


///////////////////////////////////////////////////
Infos::~Infos()
{
    //dtor
}


/////////////////////////////////////////////////
void
Infos::traiter_evenements ( const sf::Event& event )
{

    if ( event.type == sf::Event::MouseMoved )

    //  position de la souris
    if ( event.type == sf::Event::MouseMoved )
            m_mousePos = { event.mouseMove.x    , event.mouseMove.y   };
    else    m_mousePos = { event.mouseButton.x  , event.mouseButton.y };



}

/////////////////////////////////////////////////
void
Infos::actualiser ( float deltaT )
{
    if ( not estActif() ) return;

    m_compteurFPS++;

    if ( m_clock.getElapsedTime().asSeconds() > 1){
        m_clock.restart();
        m_FPS = m_compteurFPS;
        m_compteurFPS = 0;
    }

    m_lblMouseX->setTexte   ( "x: " + toString(m_mousePos.x) );
    m_lblMouseY->setTexte   ( "y: " + toString(m_mousePos.y) );
    m_lblMouseFps->setTexte ( "fps: " + toString(m_FPS) );

}


/////////////////////////////////////////////////
void
Infos::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const
{
    // le transform du gadget combiné au transform parents (states).
    states.transform *= getTransform();

    target.draw      ( *m_lblMouseX , states );
    target.draw      ( *m_lblMouseY , states );
    target.draw      ( *m_lblMouseFps , states );

}
} // fin namespace gui
