#ifndef GUI__H
#define GUI__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief Le gestionnaire d'interface (unique).
///
/////////////////////////////////////////////////
class GUI : public gui::Action, public gui::Drawable {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    /////////////////////////////////////////////////
    /// \brief Initialisation du gestionnaire d'interface (skin, polices, icones...)
    ///
    /////////////////////////////////////////////////
    void init ();

    void traiterEvenements (const sf::Event&  evenement);

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    GUI (sf::RenderWindow fenetreSFML);

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
public:
    CreateurGadget creer;    
     m_gestRessources;    ///<  Le gestionnaire des resources propres aux interfaces.    
private:
    vector<std::shared_ptr<gadgets>> m_gadgets;    ///<  la liste total des gadgets de l'interface    
    Groupe m_enfants;    
    sf::renderWindow m_fenetreSFML;    
    Skin m_skin;    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class GUI
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
