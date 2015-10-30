#ifndef FENETRE_ENCASTREE_H
#define FENETRE_ENCASTREE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/Fenetre.h>

namespace gui {


/////////////////////////////////////////////////
/// \brief les types d'ajustements des éléments entre eux.
///
/// Ajuster la taille d'un gadget par rapport à la taille d'un autre.
/// Le bouton par rapport au texte d'un BoutonTexte par exemple.
///
/////////////////////////////////////////////////
enum Encastrements {
        Gauche      ///<
    ,   Droite      ///<
    ,   Haut        ///<
    ,   Bas         ///<
};


class Fenetre_encastree: public Fenetre
{
    class BoutonSlide;

public:
    Fenetre_encastree   ( sf::RenderWindow  *       fenetre
                        , std::shared_ptr<Skin>     skin            = new Skin()
                        , Encastrements             encastrement    = Encastrements::Gauche );


    virtual ~Fenetre_encastree();

    /////////////////////////////////////////////////
    /// \brief Definir la position de la fenetre est deactivé, ne fait rien
    ///
    /// \param pos position, mais inutile
    ///
    /////////////////////////////////////////////////
    virtual void
    setPosition ( sf::Vector2f pos ) { };

    /////////////////////////////////////////////////
    /// \brief Definir la position de la fenetre est deactivé, ne fait rien
    ///
    /// \param pos position, mais inutile
    ///
    /////////////////////////////////////////////////
    virtual void
    setPosition ( float x  ,  float y ) { };







    /////////////////////////////////////////////////
    /// \brief Initialiser les gadgets ( boutons, titre...).
    ///
    /////////////////////////////////////////////////
    void
    initUI();


    /////////////////////////////////////////////////
    /// \brief mais à jour les styles des éléments de la fenêtre.
    ///
    /////////////////////////////////////////////////
    virtual void
    updateStyle( );


    /////////////////////////////////////////////////
    /// \brief Mettre à jour les gémotries de la fenêtre
    ///
    /////////////////////////////////////////////////
    void
    majGeom (  )  ;



    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    std::shared_ptr<BoutonSlide>          m_BoutonSlide;     ///<  Le Bouton glissant sur le bouton fond
    std::shared_ptr<Bouton>          m_Boutonfond;      ///<  le bouton






};
}; // fin namespace
#endif // FENETRE_ENCASTREE_H
