

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
    auto skinCourant =  Config::m_skins[ Config::Skins::Skin1 ] ;
/*
    // creation du label
    gui::Gadget::ptr    lblTest ( new gui::Label ( "ça sent l'cornichon" , *skinCourant->lblCourant ) );
    m_gui.ajouter ( lblTest );

    // creation du Bouton simple A, c'est un shared_ptr de l'ecranDemo
    this->boutonA = std::shared_ptr<gui::Bouton>   ( new gui::Bouton ( skinCourant ) );
    m_gui.ajouter                 ( this->boutonA );
    this->boutonA->setPosition    ( 50, 50 );
    this->boutonA->setSize        ({25, 25});
    this->boutonA->lier           ( gui::Evenements::onGRelache , [this]() {
        std::cout << "boutonA \n";
    });
*/
    // creation du BoutonTexte B, nouveau pointeur, ajouté aux enfants du groupe GUI principal.
    std::shared_ptr<gui::BoutonTexte>  boutonB ( new gui::BoutonTexte ( "Bouton B" , skinCourant ) );
    m_gui.ajouter           ( boutonB );
    boutonB->setPosition    ( 150, 50 );
    boutonB->setSize        ({25, 25});
    boutonB->setBordure     ( 5 );
    boutonB->ajusterAuTexte ( );
    boutonB->lier           ( gui::Evenements::onGRelache , [this]() {
        std::cout << "déclenchement de la fonction associé au boutonB.\n";
    });


}   // fin init GUI




}   // fin namespace app































