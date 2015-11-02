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

    Groupe();
    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox locale
    ///
    /// \return la boundingBox locale des éléments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( )const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox globale
    ///
    /// \return la boundingBox globale des éléments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( )const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille à l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize ( )const;

    void
    setSize ( sf::Vector2f taille );

    /////////////////////////////////////////////////
    /// \brief Rendre les éléments.
    ///
    /// Dessiner les différents éléments du ou des écrans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;


////////////// DEBUG /////////////////////////////////////
//bool
//contient ( float x, float y )
//{
//    sf::FloatRect rect  = getGlobalBounds();
//
////    ////////////DEBUG/////////////
////   // m_DEBUG_SHAPE.setPosition   ( rect.left  , rect.top      );
////    m_DEBUG_SHAPE.setSize       ( {rect.width , rect.height}   );
////    ////////////DEBUG/////////////
//
//std::cout << "Groupe -> " << rect.left << " " << rect.top << " " << rect.width << " "<< rect.height << " ------> ";
//
//    // S'il est contenu alors on verif le parent pour savoir par exemple si
//    // le gadget est visible dans la fenetre parent.
//    if ( rect.contains( sf::Vector2f ( x , y ) ) ){
//            std::cout << "TRUE\n";
//        if ( m_parent != 0 )    return  m_parent->contient ( x, y );
//        else                    return  true;
//    } else {
//            std::cout << "FALSE\n";
//        return false;
//    }
//
//};
////////////// DEBUG /////////////////////////////////////


    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    sf::Vector2f            m_taille;




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





