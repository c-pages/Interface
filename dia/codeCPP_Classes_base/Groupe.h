#ifndef GROUPE__H
#define GROUPE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////


namespace gui {

/////////////////////////////////////////////////
/// \brief 
///
/////////////////////////////////////////////////
class Groupe {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    Groupe (ptr parent);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param parent		 
    /// \param disposition		 
    /////////////////////////////////////////////////
    Groupe (ptr parent,  disposition);

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param disposition		 
    /////////////////////////////////////////////////
    setDisposition ( disposition);

    virtual void actualiser ();

    virtual void traiter_evenements (const sf::Event& evenement);

private:
    /////////////////////////////////////////////////
    /// \brief  
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
public:
    sf::Vector2i m_dispositionTaille;    ///<  ( 0 : sans limite  => {0,3} : liste horizontale en colonnes de 3 boutons )    
private:
    disposition m_disposition;    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class Groupe
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
