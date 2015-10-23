#ifndef GROUPE_H
#define GROUPE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {
/////////////////////////////////////////////////
/// \brief Gadget  Un �l�ment invisible permettant de rassembler des Gadgets au sein d'un groupe.
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
    /// \brief La gestion des �v�nements utilisateurs.
    ///
    /// G�re les entr�es claviers, souris, fenetre ...
    ///\return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    traiter_evenements ( const sf::Event& event ) ;

    /////////////////////////////////////////////////
    /// \brief Actualiser les �l�ments.
    ///
    /// Actualiser les diff�rents �l�ments du ou des �crans actifs.
    /// \param    deltaT          Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
    ///\return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    actualiser ( float deltaT ) ;

    /////////////////////////////////////////////////
    /// \brief Dessiner les diff�rents �l�ments du ou des �crans actifs.
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





