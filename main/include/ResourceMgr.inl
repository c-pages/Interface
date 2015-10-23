

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ResourceMgr.h"
namespace app
{
/////////////////////////////////////////////////
// les templates pour la gestion des ressources musicales
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// \brief Manager de ressource.
///
/// Classe template des musiques
///
/////////////////////////////////////////////////
template<typename IDENTIFIER>
template<typename ... Args>
void ResourceMgr<sf::Music,IDENTIFIER>::load(const IDENTIFIER& ident,Args&& ... args)
{
    std::unique_ptr<sf::Music> ptr(new sf::Music);
    if(not ptr->openFromFile(std::forward<Args>(args)...))
        throw std::runtime_error("Impossible de charger le fichier");
    mPlan.emplace(ident,std::move(ptr));
};

/////////////////////////////////////////////////
/// \brief Manager de ressource.
///
/// Class template des musiques
///
/////////////////////////////////////////////////
template<typename IDENTIFIER>
sf::Music& ResourceMgr<sf::Music,IDENTIFIER>::get(const IDENTIFIER& ident) const
{
    return *mPlan.at(ident);
}




/////////////////////////////////////////////////
// les templates pour la gestion des ressources types images/polices
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// \brief Manager de ressource.
///
/// Class template des polices, images
///
/////////////////////////////////////////////////
template<typename RESOURCE,typename IDENTIFIER>
template<typename ... Args>
void ResourceMgr<RESOURCE,IDENTIFIER>::load(const IDENTIFIER& ident , Args&& ... args)
{
    std::unique_ptr<RESOURCE> ptr(new RESOURCE);
    if(not ptr->loadFromFile(std::forward<Args>(args)...))
        throw std::runtime_error("Impossible de charger le fichier");
    mPlan.emplace(ident,std::move(ptr));
}



template<typename RESOURCE,typename IDENTIFIER>
RESOURCE& ResourceMgr<RESOURCE,IDENTIFIER>::get(const IDENTIFIER& ident)const
{
    return *mPlan.at(ident);
}

} // fin app
