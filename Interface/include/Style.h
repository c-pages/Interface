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
/// \brief Structure de donn�e. Un Style contient les infos visuelles d'un �l�ment.
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
/// \see gui::Skin, gui::Gadget
///
////////////////////////////////////////////////////////////
