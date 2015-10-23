#ifndef SKIN_H
#define SKIN_H
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Style.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief Un Skin définie le style de tout les éléments d'une interface graphique
///
/////////////////////////////////////////////////
struct Skin
{
    /////////////////////////////////////////////////
    /// \brief Constructeur par defaut
    ///
    /// Créer un skin avec les valeurs par défaut.
    ///
    /////////////////////////////////////////////////
    Skin();

    /////////////////////////////////////////////////
    /// \brief Constructeurs de copie
    ///
    /// Constructeur en copie d'un autre skin.
    /// \param skin le skin à copier
    ///
    /////////////////////////////////////////////////
    Skin( const Skin& skin );

    //T& T::operator=(T arg)



    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    Style  desactive;        ///< le style des gadget désactivés
    Style  fenetre;          ///< le style des fenêtres.
    Style  btnRepos;         ///< le style des boutons au repos.
    Style  btnSurvol;        ///< le style des boutons au survol.
    Style  btnPress;         ///< le style des boutons au press.
    Style  lblTitre;         ///< le style des titres.
    Style  lblCourant;       ///< le style des champs de texte courant.

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



