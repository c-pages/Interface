#ifndef BTNGLISSIERE__H
#define BTNGLISSIERE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief ( pour les contenants )
///
/////////////////////////////////////////////////
class BtnGlissiere : public gui::Bouton {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param parent		 
    /// \param orientation		 
    /////////////////////////////////////////////////
    BtnGlissiere (ptr parent, Orientation orientation);

    void setGlissiereLongueur (int );

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    int getGlissierePos ();

    virtual void actualiser ();

    virtual void traiter_evenements (const sf::Event& evenement);

private:
    virtual void init ();

    virtual void init_skin ();

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    virtual void init_interactions ();

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
private:
     m_orientation;    
    int m_longueurglissiere;    ///<       
    shared_ptr<Bouton> m_btnDrag;    
    shared_ptr<Bouton> m_btnFond;    ///<       
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class BtnGlissiere
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
