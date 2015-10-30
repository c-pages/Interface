
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets\Groupe.h"


namespace gui
{
/////////////////////////////////////////////////
Groupe::Groupe ( )
: m_taille ({0,0})
{
    std::cout << " CREER GROUPE\n";
}

///////////////////////////////////////////////////
//sf::FloatRect
//Groupe::getLocalBounds ( ) const {
//
//    sf::FloatRect result;
//
//    for ( ptr enfant : m_enfants ) {
//
//        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
//
//        if ( result.left > rect.left )   result.left = rect.left  ;
//        if ( result.top  > rect.top  )   result.top = rect.top   ;
//        if ( result.width  < rect.left + rect.width )   result.width = rect.left + rect.width  ;
//        if ( result.height < rect.top + rect.height  )   result.height = rect.top + rect.height ;
//    }
//    return { result };
//}


/////////////////////////////////////////////////
sf::FloatRect
Groupe::getGlobalBounds ( )  const{

    sf::FloatRect result;

    if ( m_taille == sf::Vector2f (0,0) ){
        for ( ptr enfant : m_enfants ) {
            sf::FloatRect rect  ( enfant->getGlobalBounds() ) ;
            if ( result.left > rect.left )                  result.left     = rect.left ;
            if ( result.top  > rect.top  )                  result.top      = rect.top   ;
            if ( result.width  < rect.left + rect.width )   result.width    = rect.left + rect.width ;
            if ( result.height < rect.top + rect.height )   result.height   = rect.top + rect.height ;
        }
    } else {
        result = sf::FloatRect  ( getPosAbs().x, getPosAbs().y, m_taille.x , m_taille.y );
    }
    return { result };
}




/////////////////////////////////////////////////
sf::FloatRect
Groupe::getLocalBounds ( )const {

    sf::FloatRect result(0,0,0,0 );

    result.left     =  getPosition().x;
    result.top      =  getPosition().y;
    result.width    =  m_taille.x;
    result.height   =  m_taille.y;

    return { result };
}

//
///////////////////////////////////////////////////
//sf::FloatRect
//Groupe::getGlobalBounds ( )const {
//    sf::FloatRect result( 0,0,0,0 );
//
//    if ( m_taille ==  sf::Vector2f (0,0) ){
//
//        result.left     +=  getPosAbs().x;// + m_posContenu.x;
//        result.top      +=  getPosAbs().y;// + m_posContenu.y;
//
//        result.width    =  m_taille.x;
//        result.height   =  m_taille.y;
//
//    } else result = sf::FloatRect  ( 0 , 0 , m_taille.x , m_taille.y );
//    return { result };
//}



/////////////////////////////////////////////////
sf::Vector2f
Groupe::getSize ( )const{
    return { getLocalBounds ( ).width , getLocalBounds ( ).height};
    /*
    return   {   getLocalBounds().width
             ,   getLocalBounds().height };*/
};

/////////////////////////////////////////////////
void
Groupe::setSize ( sf::Vector2f taille ) {

   // std::cout << "--> Groupe::setSize  ( ) : "<< this << "  " <<taille.x << "   " << taille.y<<" \n";
    this->m_taille = taille;
  // std::cout << "--> getSize -> " << this << "  >--  : " <<m_taille.x << "   " << m_taille.y<<" \n";
};


/////////////////////////////////////////////////
void
Groupe::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const
{
//    std::cout << "-->-->-- Groupe::draw  ( )  \n";
    // le transform du gadget combiné au transform parents (states).
    states.transform *= getTransform();

    // dessiner les gadgets enfants
    for ( const ptr& enfant : m_enfants )
        target.draw      ( *enfant , states );
}
} // fin namespace gui


