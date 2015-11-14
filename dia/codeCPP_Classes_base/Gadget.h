#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief Classe communes à tout les gadgets, gère affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public gui::Geometrie, public gui::Heritage {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Gadget ();

    /////////////////////////////////////////////////
    /// \brief Acceder à l'id du gadget.
    ///
    /////////////////////////////////////////////////
    unsigned int getID () const;

    /////////////////////////////////////////////////
    /// \brief Definir l'id du gadget.
    ///
    /// \param id		 la nouvel id
    /////////////////////////////////////////////////
    void setID (unsigned int id);

    /////////////////////////////////////////////////
    /// \brief Definir l'activité du gadget.
    ///
    /// \param etat		 le nouvel etat du gadget (actif ou inactif).
    /////////////////////////////////////////////////
    void setActif (bool etat);

    /////////////////////////////////////////////////
    /// \brief Acceder à l'activité du gadget.
    ///
    /////////////////////////////////////////////////
    bool getActif () const;

    /////////////////////////////////////////////////
    /// \brief Definir à la visibilité du gadget.
    ///
    /// \param valeur		 
    /////////////////////////////////////////////////
    void setVisible (bool valeur);

    /////////////////////////////////////////////////
    /// \brief Definir la visibilité du gadget.
    ///
    /////////////////////////////////////////////////
    bool getVisible () const;

protected:
    /////////////////////////////////////////////////
    /// \brief Initialiser le gadget, pointeurs, gemoétrie,skin, interactions
    ///
    /////////////////////////////////////////////////
    virtual void init ();

    /////////////////////////////////////////////////
    /// \brief Actualiser les géométrie du gadgets et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    /////////////////////////////////////////////////
    /// \brief  Traitement des évènements  du gadget.
    ///
    /// \param evenement		 L'evenemnt SFML à traiter.
    /////////////////////////////////////////////////
    virtual void traiter_evenements (const sf::Event& evenement);

    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target		 
    /// \param states		 
    /////////////////////////////////////////////////
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
private:
    unsigned int m_id;    ///<  l'id unique du gadget dans la liste des enfants de son parent. L'id correspond à l'ordre de cette liste => ordre de dessins + ordre pour "contient()".    
    bool m_actif;    ///<  le gadget est il actif ?    
    bool m_visible;    ///<  est il visible ? ( si non visible : inactif ?)    
protected:
    ptr m_this;    ///<  un pointeur partagé vers ce gadget (this)    
    GUI* m_gui;    ///<  Pointeur vers le gestionnaire d'interface graphique.    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class Gadget
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////