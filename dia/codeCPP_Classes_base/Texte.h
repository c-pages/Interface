#ifndef TEXTE__H
#define TEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief 
///
/////////////////////////////////////////////////
class Texte : public gui::affichage {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    Texte (ptr parent);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param parent		 
    /// \param texte		 
    /////////////////////////////////////////////////
    Texte (ptr parent, string texte);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param texte		 
    /////////////////////////////////////////////////
    void setTexte (string texte);

    virtual void init ();

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    virtual void init_skin ();

    virtual void actualiser ();

    virtual void actualiser_bounds ();

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
private:
    sf::Text* m_labelSFML;    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class Texte
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
