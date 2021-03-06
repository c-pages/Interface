#ifndef HERITAGE__H
#define HERITAGE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief 
///
/////////////////////////////////////////////////
class Heritage {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    Heritage ();

    /////////////////////////////////////////////////
    /// \brief Definir comme parent.
    ///
    /// \param parent		 le nouveau parent.
    /////////////////////////////////////////////////
    void setParent (ptr parent);

    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget dans la liste d'enfants de celuici.
    ///
    /// \param enfant		 L'enfant à ajouter.
    /////////////////////////////////////////////////
    virtual void ajouter (ptr enfant);

    /////////////////////////////////////////////////
    /// \brief  Supprimer l'enfant dans la listes m_enfants.
    ///
    /// \param enfant		 L'enfant à ajouter
    /////////////////////////////////////////////////
    virtual void supprimer (ptr enfant);

protected:
    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_supprimer ();

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const;

    /////////////////////////////////////////////////
    /// \brief  Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget à mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    void mettre_auDessus (ptr gadget);

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
private:
    Gadget* m_parent;    ///<  le Gadget parent.    
    Groupe m_enfants;    ///<  les Gadgets enfants.    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class Heritage
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
