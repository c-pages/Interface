#ifndef SKIN_H
#define SKIN_H
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Style.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief Un Skin d�finie le style de tout les �l�ments d'une interface graphique
///
/////////////////////////////////////////////////
struct Skin
{
    /////////////////////////////////////////////////
    /// \brief Constructeur par defaut
    ///
    /// Cr�er un skin avec les valeurs par d�faut.
    ///
    /////////////////////////////////////////////////
    Skin();

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    Style * fenetre;          ///< le style des fen�tres.
    Style * btnRepos;         ///< le style des boutons au repos.
    Style * btnSurvol;        ///< le style des boutons au survol.
    Style * btnPress;         ///< le style des boutons au press.
    Style * lblTitre;         ///< le style des titres.
    Style * lblCourant;       ///< le style des champs de texte courant.

};
}; // fin namespace gui
#endif // SKIN_H

////////////////////////////////////////////////////////////
/// \struct gui::Skin
/// \ingroup interface
///
/// Definie un style global de la scene en cummulant les styles pour chaques types de gadgets.
///
/// \see gui::Style
///
////////////////////////////////////////////////////////////



