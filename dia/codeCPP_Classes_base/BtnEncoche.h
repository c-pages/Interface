#ifndef BTNENCOCHE__H
#define BTNENCOCHE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief ( interupteur )
///
/////////////////////////////////////////////////
class BtnEncoche : public gui::Bouton {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    BtnEncoche (ptr parent);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param parent		 
    /// \param texte		 
    /// \param coché		 
    /////////////////////////////////////////////////
    BtnEncoche (ptr parent, string texte, bool coché = true);

    void setCoche (bool );

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    bool getCoche () const;

    string setTexte ();

    void setCocheIcone (const sf::Texture* icone);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param 		 
    /////////////////////////////////////////////////
    void setFondIcone (const sf::Texture* );

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
    EtatBouton m_etat;    ///<  ( inactif , repos, survol, presse  )    
    bool m_cocheEtat;    ///<       
    shared_ptr<Label> m_label;    
    shared_ptr<Image> m_cocheIcone;    
    shared_ptr<Image> m_fondIcone;    
    shared_ptr<Bouton> m_bouton;    ///<       
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class BtnEncoche
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
