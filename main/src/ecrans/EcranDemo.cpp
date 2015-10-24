

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>
#include "GUI.h"

namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran     ( appli )
, m_gui     (  )
{
    // Initialisation de l'interface graphique.
    initGUI     ();
    initScene   ();
}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...

    // Evenements de l'interface
    m_gui.traiter_evenements    ( event );
}


/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_gui.actualiser    ( deltaT );
}


/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    // Dessiner la fenetre du jeu
    m_appli->getFenetre().draw ( m_fond );

    // Dessiner l'interface
    m_appli->getFenetre().draw ( m_gui );
}


/////////////////////////////////////////////////
void
EcranDemo::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }


/////////////////////////////////////////////////
void
EcranDemo::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );
    m_fond.setFillColor ( sf::Color (50,50,50));
}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ( )
{
    // le skin qu'on va utiliser dans cette interface
    gui::Skin skinCourant = gui::Skin ( Config::m_skins[ Config::Skins::Skin1 ] );

    // creation du label
    gui::Gadget::ptr    lblTest ( new gui::Label ( "ça sent l'cornichon" , Config::m_skins[ Config::Skins::Skin1 ].lblCourant ) );
    m_gui.ajouter ( lblTest );

    // creation du Bouton
    this->boutonA = gui::Gadget::ptr ( new gui::Bouton (  Config::m_skins[ Config::Skins::Skin1 ] ) );

    m_gui.ajouter           ( this->boutonA );
    this->boutonA->setPosition    ( 50, 50 );
    this->boutonA->setSize        ({25, 25});
    this->boutonA->setSkin        ( Config::m_skins[ Config::Skins::Skin1 ] );
    this->boutonA->lier           ( gui::Evenements::onEntre , [this]() {
        this->boutonA->move (25,0);
        this->boutonA->rotate (5);
    });

}   // fin init GUI




}   // fin namespace app































