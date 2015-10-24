#ifndef STYLE_H
#define STYLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
//#include <../GUI.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief Alignement d'un �l�ments par rapport � un autre.
///
/// Par exemple:
/// \li ponctuelement, le texte par rapport au bouton dans un BoutonTexte.
/// \li les �l�ments dans une fen�tre...
///
/////////////////////////////////////////////////
enum Alignements {
        Libre       ///<
    ,   Haut_Gche   ///<  haut Gauche
    ,   Ctre_Gche   ///<  Centre Gauche
    ,   Bas_Gche    ///<  Bas Gauche
    ,   Haut_Mili   ///<  haut Milieu
    ,   Ctre_Mili   ///<  Centre Milieu
    ,   Bas_Mili    ///<  Bas Milieu
    ,   Haut_Drte   ///<  Droite haut
    ,   Ctre_Drte   ///<  Droite Centre
    ,   Bas_Drte    ///<  Droite Bas
};

/////////////////////////////////////////////////
/// \brief les types d'ajustements des �l�ments entre eux.
///
/// Ajuster la taille d'un gadget par rapport � la taille d'un autre.
/// Le bouton par rapport au texte d'un BoutonTexte par exemple.
///
/////////////////////////////////////////////////
enum Ajustements {
        Sans            /** */
    ,   Vert            /** Verticalement*/
    ,   Hori            /** Horizontalement*/
    ,   Vert_Hori       /** Verticalement et Horizontalement*/
};

/////////////////////////////////////////////////
/// \brief Un style contient les infos visuelles d'un �l�ment.
///
/// Un Style contient les couleurs, tailles(lignes),
/// polices, etc. qui seront appliqu�s � un Gadget.
///
/////////////////////////////////////////////////
struct Style
{

public:

    /////////////////////////////////////////////////
    /// \brief Constructeurs
    ///
    /////////////////////////////////////////////////
    Style();

    /////////////////////////////////////////////////
    /// \brief Constructeurs de copie
    ///
    /// Constructeur en copie d'un autre style.
    /// \param source le style � copier
    ///
    /////////////////////////////////////////////////
    Style( const Style& source );




    void
    print()
    {
        std::cout << " Style ----------------------------";
        std::cout << "\n      txt_taille = " << txt_taille;
        std::cout << "\n      lgn_epaisseur = " << lgn_epaisseur;
        std::cout << "\n      txt_couleur = " << int (txt_couleur.r) << " " << int (txt_couleur.g) << " " << int (txt_couleur.b) << " " << int (txt_couleur.a) << "\n" ;
    }








    ////////////////////////////////////////////////////////////
    // Les membres
    ////////////////////////////////////////////////////////////
    sf::Font                txt_police;     ///<  Police du texte.
    sf::Text::Style         txt_style;      ///<  Style SFML du texte (Regular, Italic, ... ).
    float                   txt_taille;     ///<  Taille du texte.
    sf::Color               txt_couleur;    ///<  Couleur du texte.
    float                   lgn_epaisseur;  ///<  Epaisseur des lignes.
    sf::Color               lgn_couleur;    ///<  Couleur des lignes.
    sf::Color               fnd_couleur;    ///<  Couleur du fond.
    sf::Texture             fnd_texture;    ///<  Texture du fond au repos.
    Alignements             align;          ///<  Alignement.
    Ajustements             ajust;          ///<  Ajustement.

};

}; // fin namespace gui

#endif // STYLE_H

////////////////////////////////////////////////////////////
/// \class gui::Style
/// \ingroup interface
///
/// Definie un style de rendu, commel'�paisseur des lignes, la couleur ou la texture
/// du fond, la police utilis� ...
///
/// \see sf::RectangleShape, sf::CircleShape, sf::ConvexShape, sf::Transformable
///
////////////////////////////////////////////////////////////
