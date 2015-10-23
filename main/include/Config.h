#ifndef CONFIG_H
#define CONFIG_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <map>
#include <ResourceMgr.h>
#include <GUI.h>
#include <Style.h>


namespace app
{

/////////////////////////////////////////////////
/// \brief Contient les différents éléments de Configuration de l'application.
///
/////////////////////////////////////////////////
class Config
{
public:

    enum Polices                :  int  {   police_1
                                        ,   police_2   };

    enum Styles                 :  int  {   root
                                        ,   Bouton
                                        ,   Fenetre   };

    enum Skins                  :  int  {   Skin1   };

    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /////////////////////////////////////////////////
    Config();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Config();


    /////////////////////////////////////////////////
    /// \brief Initialiser les differents élément
    ///
    /// \li les textures
    /// \li les polices
    /// \li les styles
    /// \li les sons (à prévoir)
    /// \li les musiques (à prévoir)
    ///
    /////////////////////////////////////////////////
    static void init();

    /////////////////////////////////////////////////
    /// \brief Initialise le manager de textures.
    ///
    /////////////////////////////////////////////////
    static void initTextures();

    /////////////////////////////////////////////////
    /// \brief Initialise le Manager des polices.
    ///
    /////////////////////////////////////////////////
    static void initPolices();

    /////////////////////////////////////////////////
    /// \brief Initialiser les differents skins pour l'interface graphique
    ///
    /////////////////////////////////////////////////
    static void initSkins();

    /////////////////////////////////////////////////
    /// \brief Initialiser les differents styles pour l'interface graphique
    ///
    /////////////////////////////////////////////////
    static void initStyles();

    /////////////////////////////////////////////////
    /// \brief recuperer la durée d'une image
    ///
    /////////////////////////////////////////////////
    static sf::Time getDureeImage();


    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    static  ResourceMgr<sf::Texture,int>        m_textures;     ///< Manager des textures
    static  ResourceMgr<sf::Font,int>           m_polices;      ///< Manager des polices
    static  std::map < Styles , gui::Style >   m_styles;       ///< les styles pour le GUI \todo passer de pointer* à point shared_ptr ou unique_ptr ?
    static  std::map < Skins  , gui::Skin >    m_skins;        ///< les styles pour le GUI \todo passer de pointer* à point shared_ptr ou unique_ptr ?
private:
    static  sf::Time                            m_dureeImage;   ///< Durée d'une image, Autrement dit on a 1/FrameRate = \e DureeImage



};
}; // fin app
#endif // CONFIG_H


////////////////////////////////////////////////////////////
/// \class app::Config
/// \ingroup application
///
/// Configuration des textures, sons, musiques polices, tailles, couleurs ....
///
/// \see app::Ecran, app::Gestion_ecrans
///
////////////////////////////////////////////////////////////

