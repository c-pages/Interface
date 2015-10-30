#ifndef GROUPE_H
#define GROUPE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {
/////////////////////////////////////////////////
/// \brief Gadget  Un �l�ment invisible permettant de rassembler des Gadgets.
///
/////////////////////////////////////////////////
class Groupe : public Gadget
{
public:

    Groupe();
    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox locale
    ///
    /// \return la boundingBox locale des �l�ments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( )const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox globale
    ///
    /// \return la boundingBox globale des �l�ments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( )const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille � l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize ( )const;

    void
    setSize ( sf::Vector2f taille );



    /////////////////////////////////////////////////
    /// \brief Rendre les �l�ments.
    ///
    /// Dessiner les diff�rents �l�ments du ou des �crans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;


    sf::Vector2f            m_taille;
};
};
#endif // GROUPE_H



////////////////////////////////////////////////////////////
/// \class gui::Groupe
/// \ingroup interface
///
/// �a fait pas grand chose de plus qu'un Gadget, � part les trucs de taille et BB � partir des enfants du groupe.
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////





