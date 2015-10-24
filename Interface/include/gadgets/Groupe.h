#ifndef GROUPE_H
#define GROUPE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {
/////////////////////////////////////////////////
/// \brief Gadget  Un élément invisible permettant de rassembler des Gadgets.
///
/////////////////////////////////////////////////
class Groupe : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox locale
    ///
    /// \return la boundingBox locale des éléments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( ) ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox globale
    ///
    /// \return la boundingBox globale des éléments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille à l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize ( );

    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// Actualiser les différents éléments du ou des écrans actifs.
    /// \param deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ( float deltaT ) ;
};
};
#endif // GROUPE_H



////////////////////////////////////////////////////////////
/// \class gui::Groupe
/// \ingroup interface
///
/// ça fait pas grand chose de plus qu'un Gadget, à part les trucs de taille et BB à partir des enfants du groupe.
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////





