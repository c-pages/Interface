
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets\Groupe.h"


namespace gui
{

/////////////////////////////////////////////////
sf::FloatRect
Groupe::getLocalBounds ( ) {
    sf::FloatRect result;

    for ( ptr enfant : m_enfants ) {

        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;

        if ( result.left > rect.left )   result.left = rect.left  ;
        if ( result.top  > rect.top  )   result.top = rect.top   ;
        if ( result.width  < rect.left + rect.width - result.left )   result.width = rect.left + rect.width - result.left ;
        if ( result.height < rect.top + rect.height - result.top  )   result.height = rect.top + rect.height - result.top ;

    }
    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
Groupe::getGlobalBounds ( ) {
    sf::FloatRect result;
    for ( ptr enfant : m_enfants ) {

        sf::FloatRect rect  ( enfant->getGlobalBounds() ) ;

        if ( result.left > rect.left )   result.left = rect.left  ;
        if ( result.top  > rect.top  )   result.top = rect.top   ;
        if ( result.width  < rect.left + rect.width - result.left )   result.width = rect.left + rect.width - result.left ;
        if ( result.height < rect.top + rect.height - result.top  )   result.height = rect.top + rect.height - result.top ;
    }
    return { result };
}


/////////////////////////////////////////////////
sf::Vector2f
Groupe::getSize ( ){
    return   {   getLocalBounds().width
             ,   getLocalBounds().height };
};

} // fin namespace gui


