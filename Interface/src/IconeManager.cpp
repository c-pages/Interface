/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "IconeManager.h"
#include <iostream>

namespace gui
{

//
//// initialiser      membre static
//IconeManager     IconeManager::icoMngr = IconeManager ();
//
//std::map<Icone, sf::Texture *>  m_textures ;

///////////////////////////////////////////////////
IconeManager::IconeManager()
{
    //ctor
}
//////////////////////////////////////////////////
IconeManager::~IconeManager()
{
    //dtor
}



//////////////////////////////////////////////////
//void
//IconeManager::init(  )
//{
//    // init des icones
//    charger( Icone::Fermer , "../Interface/media/img/ico_fermer.png" );
//    charger( Icone::Fleche , "../Interface/media/img/ico_fleche.png" );
//}



//////////////////////////////////////////////////
void
IconeManager::charger( Icone nom , const std::string& fichier )
{
    // charger la texture
    sf::Texture * tex= new sf::Texture();
    tex->loadFromFile( fichier );

    // on l'ajoute à la liste
    m_textures[ nom ] = tex;
}

//////////////////////////////////////////////////
const sf::Texture*
IconeManager::acceder( Icone texture)
{
    return  m_textures.at(texture);
}


} // fin namespace gui
