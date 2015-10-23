
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Action.h"
#include <iostream>

namespace gui {

/////////////////////////////////////////////////
// Init deftype fonction pour liaison
/////////////////////////////////////////////////
Action::FuncType     Action::defaultFunc = [](  )->void{};


/////////////////////////////////////////////////
void
Action::lier    ( Evenements evt ,      const FuncType& fonction )
{
    this->_evtsSouris.insert( { evt , fonction } );
}


/////////////////////////////////////////////////
void
Action::lier      (  sf::Keyboard::Key touche ,  const FuncType& fonction )
{
    _evtsClavier.insert( { touche  , fonction } );
}


/////////////////////////////////////////////////
void
Action::delier     ( Evenements evt )
{
    _evtsSouris.erase( evt  );
}


/////////////////////////////////////////////////
void
Action::delier  ( sf::Keyboard::Key  touche)
{
    _evtsClavier.erase( touche  );
}


/////////////////////////////////////////////////
void
Action::declencher (Evenements evt )
{
    auto fct = _evtsSouris.find( evt );
    if( fct != _evtsSouris.end())
        fct->second();
}


/////////////////////////////////////////////////
bool
Action::traiter_evenements   (const sf::Event& event)
{
    if ( event.type == sf::Event::KeyReleased )
        for (auto evt : _evtsClavier)
            if (event.key.code == evt.first)
                evt.second();
   return true;
}

}// fin du namespace gui
