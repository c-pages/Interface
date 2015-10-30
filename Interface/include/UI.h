#ifndef UI_H
#define UI_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <Gadget.h>
#include <gadgets/Groupe.h>


namespace gui{
class UI
{

public:
    UI();
    virtual ~UI();

    /////////////////////////////////////////////////
    /// \brief Pour lier les élément de l'interface de la fenetre à la fenêtre
    ///
    /// \param enfant un élément de l'interface de la fenêtre.
    ///
    /////////////////////////////////////////////////
    virtual void
    ajouterUI( Gadget::ptr enfant );



    /////////////////////////////////////////////////
    /// \brief Initialiser les gadgets ( boutons, titre...).
    ///
    /////////////////////////////////////////////////
    virtual void
    creerUI();



    //    virtual void
    //    dessinerUI ( sf::RenderTarget& target, sf::RenderStates states ) const ;

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    std::shared_ptr<Groupe> m_UI;       ///<  les éléments d'interface du gadget


protected:
private:

};
}; // fin namespace

#endif // UI_H
