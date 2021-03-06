#ifndef BOUTONRADIO_H
#define BOUTONRADIO_H



/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief Gadget, permet de selectionner une ou plusieurs options parmis au moins deux choix.
///
/// chaque choix se presente sous la forme d'un boutonEncoche associ� � un label.
/// On aura la possibilit� � la cr�ation de choisir le nobre d'option � la fois possible (min 1).
///
/// \todo � developper.
///
/////////////////////////////////////////////////
class BoutonRadio : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /////////////////////////////////////////////////
    BoutonRadio();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~BoutonRadio();

protected:

private:

    /////////////////////////////////////////////////
    // Les Membres
    /////////////////////////////////////////////////


};

}; // fin namespace gui
////////////////////////////////////////////////////////////
/// \class gui::BoutonRadio
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////






#endif // BOUTONRADIO_H
