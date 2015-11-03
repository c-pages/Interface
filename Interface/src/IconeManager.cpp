/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "IconeManager.h"
#include <iostream>

namespace gui
{
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
void
IconeManager::charger( Icone nom , const std::string& fichier )
{
    std::cout << "charger 1 \n";
    // charger la texture
    sf::Texture * tex= new sf::Texture();
    std::cout << "charger 2 \n";
    tex->loadFromFile( fichier );
    std::cout << "charger 3 \n";

    // on l'ajoute à la liste
    m_textures[ nom ] = tex;
    std::cout << "charger 4 \n";
}

const sf::Texture*
IconeManager::acceder( Icone texture)
{
    return  m_textures.at(texture);
}


} // fin namespace gui
