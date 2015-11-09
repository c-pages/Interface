#ifndef ICONEMANAGER_H
#define ICONEMANAGER_H




/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <string>
#include <SFML/Graphics.hpp>


namespace gui
{


// les icones ....
enum Icone {
    Fermer,
    FlecheBas,
    FlecheHaut
};

// les curseurs ....
enum Curseur {
    redim_vert,
    redim_hori,
    redim_diag1,
    redim_diag2
};



/////////////////////////////////////////////////
/// \brief premet de gerer en RAII les textures pour les icones de l'ui.
///
/////////////////////////////////////////////////
class IconeManager
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    IconeManager();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~IconeManager();


    /////////////////////////////////////////////////
    /// \brief charger une nouvelle texture d'icone
    ///
    /// \param  nom         le nom indexé de la texture
    /// \param  fichier     l'adresse du fichier de la texture
    ///
    /////////////////////////////////////////////////
    void
    charger( Icone nom , const std::string &fichier);


    /////////////////////////////////////////////////
    /// \brief charger une nouvelle texture de curseur
    ///
    /// \param  nom         le nom indexé de la texture
    /// \param  fichier     l'adresse du fichier de la texture
    ///
    /////////////////////////////////////////////////
    void
    charger( Curseur nom , const std::string &fichier);


    /////////////////////////////////////////////////
    /// \brief acceder à une Icone
    ///
    /// \param texture le nom indexé de la texture auquel on veut acceder
    ///
    /////////////////////////////////////////////////
    const sf::Texture*
    acceder( Icone texture);

    /////////////////////////////////////////////////
    /// \brief acceder à un curseur
    ///
    /// \param texture le nom indexé de la texture auquel on veut acceder
    ///
    /////////////////////////////////////////////////
    const sf::Texture*
    acceder( Curseur texture );

//    /////////////////////////////////////////////////
//    /// \brief initialisation des textures des icones
//    ///
//    /////////////////////////////////////////////////
//    static void
//    init( );

protected:

private:

    /////////////////////////////////////////////////
    // Les Membres
    /////////////////////////////////////////////////
    std::map<Icone, sf::Texture *>      m_textures;   ///<  liste des textures pour les icones de l'ui.
    std::map<Curseur, sf::Texture *>    m_curseurs;   ///<  liste des textures pour les curseurs de l'ui.

//
//public:
//    static IconeManager     icoMngr;

};

////////////////////////////////////////////////////////////
/// \class gui::IconeManager
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////



}; // fin namespace gui




#endif // ICONEMANAGER_H
