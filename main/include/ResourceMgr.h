#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>

namespace app
{

/////////////////////////////////////////////////
/// \brief Manager de ressource (polices, images).
///
/// Classe template des polices, images
///
/////////////////////////////////////////////////
template<typename RESOURCE,typename IDENTIFIANT = int>
class ResourceMgr
{
    public:
        ResourceMgr             ( const ResourceMgr& ) = delete;
        ResourceMgr& operator=  ( const ResourceMgr& ) = delete;
        ResourceMgr             ( ) = default;

        template<typename ... Args>
        void        load(const IDENTIFIANT& id,Args&& ... args);

        RESOURCE&   get(const IDENTIFIANT& id)const;

    private:

        std::unordered_map<IDENTIFIANT,std::unique_ptr<RESOURCE>>       mPlan;
};


/////////////////////////////////////////////////
/// \brief Manager de ressource (music).
///
/// Classe template des musiques
///
/////////////////////////////////////////////////
template<typename IDENTIFIER>
class ResourceMgr<sf::Music,IDENTIFIER>
{
    public:
        ResourceMgr(const ResourceMgr&) = delete;
        ResourceMgr& operator=(const ResourceMgr&) = delete;
        ResourceMgr() = default;

        template<typename ... Args>
        void load(const IDENTIFIER& id,Args&& ... args);

        sf::Music& get(const IDENTIFIER& id)const;
    private:
        std::unordered_map<IDENTIFIER,std::unique_ptr<sf::Music>> mPlan;
};


}; // fin app

#include <ResourceMgr.inl>



#endif // RESOURCEMGR_H

////////////////////////////////////////////////////////////
/// \class app::ResourceMgr
/// \ingroup application
///
/// Gère les ressource façon ASII (  recuperé dans \e SFML Blueprints [eBook] )
///
/// \see app::Ecran, app::Gestion_ecrans
///
////////////////////////////////////////////////////////////
