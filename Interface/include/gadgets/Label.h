
#ifndef LABEL_H
#define LABEL_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <string>
#include <Gadget.h>

namespace gui
{

class Style;

/////////////////////////////////////////////////
/// \brief Gadget  Un simple Label permettant d'afficher un texte.
///
/////////////////////////////////////////////////
class Label : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur defaut, avec ou sans texte
    ///
    /// \param texte       Le texte à afficher.
    ///
    /////////////////////////////////////////////////
    Label    ( std::string     texte ="" );

    /////////////////////////////////////////////////
    /// \brief Constructeur, avec texte et style
    ///
    /// \param texte       Le texte à afficher.
    /// \param style       Le style à appliquer (Style).
    ///
    /////////////////////////////////////////////////
    Label   ( std::string     texte
            , Style * style );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Label();

    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille du texte.
    ///
    /// \return la taille
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \returnLa boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( );

    //======================================================================
    //==========     Parametres ( access./mut.)  ===========================
    //======================================================================

    /////////////////////////////////////////////////
    /// \brief Definir le texte du Label.
    ///
    /// \param texte     Le nouveau texte
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    setTexte ( std::string texte ) {  m_texte->setString(texte);   } ;

    /////////////////////////////////////////////////
    /// \brief Accesseur du texte du Label.
    ///
    /// \return le texte du Label.
    ///
    /////////////////////////////////////////////////
    std::string
    getTexte ( std::string texte ) {  return m_texte->getString();   } ;

    /////////////////////////////////////////////////
    /// \brief Definir la taille texte du Label.
    ///
    /// \param taille     Le taille des charactere du label.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    setTexteTaille ( float taille ) {  m_texte->setCharacterSize(taille);  };

    /////////////////////////////////////////////////
    /// \brief Definir la couleur du texte du Label.
    ///
    /// \param col     la couleur du texte
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    setColor ( sf::Color col ) { m_texte->setColor( col ); } ;

    /////////////////////////////////////////////////
    /// \brief Actualise le style du label
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    updateStyle( );

    /////////////////////////////////////////////////
    /// \brief La gestion des évènements utilisateurs.
    ///
    /// \param Gère les entrées claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// Actualiser les différents éléments du ou des écrans actifs.
    ///
    /// \param deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    actualiser ( float deltaT );

    /////////////////////////////////////////////////
    /// \brief Rendre les différents éléments du ou des écrans actifs.
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

protected:
    //sf::Text
    sf::Text *              m_texte;    ///< Le text SFML.

};
}; // fin gui

#endif // LABEL_H



////////////////////////////////////////////////////////////
/// \class gui::Label
/// \ingroup interface
///
/// exemple :
/// \code
/// // gui::Gadget::ptr est le type pour un shared pointer vers un gadget.
/// gui::Gadget::ptr    lblTest ( new gui::Label ( "Ceci est un gui::Label" , skinCourant->lblCourant ) );
/// m_gui.ajouter ( lblTest );
/// \endcode
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////

















