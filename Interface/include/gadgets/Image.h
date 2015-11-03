#ifndef IMAGE_H
#define IMAGE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {

/////////////////////////////////////////////////
/// \brief Gadget  Un simple gadget permettant d'afficher une image ou une couleur uni.
///
/////////////////////////////////////////////////
class Image : public Gadget
{

public:

    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /////////////////////////////////////////////////
    Image();

    /////////////////////////////////////////////////
    /// \brief    Constructeur.
    ///
    /// \param    fichier       L'adresse du fichier image à charger( .jpg, .png, ... ).
    /// \param    taille        La taille de l'image affichée.
    ///
    /////////////////////////////////////////////////
    Image( std::string  fichier , sf::Vector2f     taille  = {0,0} );

    /////////////////////////////////////////////////
    /// \brief    Constructeur.
    ///
    /// \param    couleur       La couleur à afficher
    /// \param    taille        La taille de l'image affichée.
    ///
    /////////////////////////////////////////////////
    Image( sf::Color    couleur , sf::Vector2f     taille  = {0,0} );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Image();

    /////////////////////////////////////////////////
    /// \brief    Definir la taille du bouton.
    ///
    /// \return   la taile du bouton
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize( ) const;

    /////////////////////////////////////////////////
    /// \brief    Definir la taille du bouton.
    ///
    /// \param    taille     La nouvelle taille.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    void
    setSize( sf::Vector2f taille );

    /////////////////////////////////////////////////
    /// \brief    Accesseur de la boundingBox en local
    ///
    /// \return   La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( ) const;

    /////////////////////////////////////////////////
    /// \brief    Accesseur de la boundingBox en global
    ///
    /// \return   La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) const;

    /////////////////////////////////////////////////
    /// \brief    Definir Couleur du fond.
    ///
    /// \param    color     La nouvelle Couleur du fond.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setFillColor ( sf::Color color );

    /////////////////////////////////////////////////
    /// \brief    Definir Couleur du cadre.
    ///
    /// \param    color     La nouvelle Couleur du cadre.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setOutlineColor  ( sf::Color color );

    /////////////////////////////////////////////////
    /// \brief    Definir Couleur du cadre.
    ///
    /// \param    epaisseur     La nouvelle epaisseur du cadre.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setOutlineThickness  ( float epaisseur );

    /////////////////////////////////////////////////
    /// \brief    Definir la texture de l'image.
    ///
    /// \param    texture     La nouvelle texture à appliquer.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    void
    setTexture      ( const sf::Texture*   texture );

    /////////////////////////////////////////////////
    /// \brief    Charger une image.
    ///
    /// \param    fichier     L'adresse du fichier le l'image.
    /// \return   Rien
    ///
    /////////////////////////////////////////////////
    void
    loadImage      ( std::string fichier  );


    /////////////////////////////////////////////////
    /// \brief    Rendre les différents éléments du ou des écrans actifs.
    ///
    /////////////////////////////////////////////////
    void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

private:

    /////////////////////////////////////////////////
    /// \brief    Initialisation
    ///
    /////////////////////////////////////////////////
    void
    Init ();

    /////////////////////////////////////////////////
    /// \brief    Mise a jour des gemotries ( size, pos, couleur, textures..)
    ///
    /////////////////////////////////////////////////
    void
    majGeom ();

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::RectangleShape *   m_rectangle;  ///<  le rectangle sur lequel on applique la texture.
    sf::Texture            m_texture;    ///<  la texture.
    sf::Image              m_image;      ///<  l'image.

};
};

#endif // IMAGE_H

////////////////////////////////////////////////////////////
/// \class gui::Image
/// \ingroup interface
///
/// sert à faire les fond des gadgets.
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////

