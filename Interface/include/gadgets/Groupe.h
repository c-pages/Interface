#ifndef GROUPE_H
#define GROUPE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {
/////////////////////////////////////////////////
/// \brief Gadget  Un élément invisible permettant de rassembler des Gadgets au sein d'un groupe.
///
/////////////////////////////////////////////////
class Groupe : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox locale
    ///
    /// \return la boundingBox locale.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( ) ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox globale
    ///
    /// \return la boundingBox globale.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la boundingBox taille.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize ( );

    /////////////////////////////////////////////////
    /// \brief La gestion des évènements utilisateurs.
    ///
    /// Gère les entrées claviers, souris, fenetre ...
    ///\return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    traiter_evenements ( const sf::Event& event ) ;

    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// Actualiser les différents éléments du ou des écrans actifs.
    /// \param    deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    ///\return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    actualiser ( float deltaT ) ;

    /////////////////////////////////////////////////
    /// \brief Dessiner les différents éléments du ou des écrans actifs.
    ///
    ///\return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;

};
};
#endif // GROUPE_H



////////////////////////////////////////////////////////////
/// \class gui::Groupe
/// \ingroup interface
///
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////





