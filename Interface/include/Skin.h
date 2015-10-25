#ifndef SKIN_H
#define SKIN_H
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <Style.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief Structure de donn�e. Un Skin d�finie un ensemble de Style pour les �l�ments d'une interface graphique.
///
/// C'est l'assemblage de plein de Style dans lequel les Gadget viennent piocher en fonction des besoins.
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
    /// \brief Constructeurs de copie
    ///
    /// Constructeur en copie d'un autre skin.
    /// \param skin le skin � copier
    ///
    /////////////////////////////////////////////////
    Skin( const Skin& skin );

    //T& T::operator=(T arg)



    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    std::shared_ptr <Style>  desactive;        ///< le style des gadgets d�sactiv�s
    std::shared_ptr <Style>  fenetre;          ///< le style des fen�tres.
    std::shared_ptr <Style>  btnRepos;         ///< le style des boutons au repos.
    std::shared_ptr <Style>  btnSurvol;        ///< le style des boutons au survol.
    std::shared_ptr <Style>  btnPress;         ///< le style des boutons au press.
    std::shared_ptr <Style>  lblTitre;         ///< le style des titres.
    std::shared_ptr <Style>  lblCourant;       ///< le style des champs de texte courant.
    std::shared_ptr <Style>  invisible;        ///< le style pour les bouton invisible par exemple

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



