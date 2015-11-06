
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


/////////////////////////////////////////////////
bool
Groupe::contient ( float x, float y )
{
/*
    //////////// DEBUG /////////////////////////////////////

    sf::FloatRect rect  = getGlobalBounds();
    std::cout << "Groupe -> " << rect.left << " " << rect.top << " " << rect.width << " "<< rect.height << " ------> ";

        // S'il est contenu alors on verif le parent pour savoir par exemple si
        // le gadget est visible dans la fenetre parent.
        if ( rect.contains( sf::Vector2f ( x , y ) ) ){
                std::cout << "TRUE\n";
    //        if ( m_parent != 0 )    return  m_parent->contient ( x, y );
    //        else
                return  true;
        } else {
                std::cout << "FALSE\n";
    //        return false;
        }
    ////////// DEBUG /////////////////////////////////////*/

    // si pas de parent return true
    if ( m_parent == nullptr ) return true;

    // sinon on regarde si parent contient x,y
    return  m_parent->contient ( x, y );
};


/////////////////////////////////////////////////
sf::FloatRect
Groupe::getGlobalBounds ( )  const{
    sf::FloatRect result ( 0,0,0,0 );

 //   std::cout << "      getPosAbs : " << getPosAbs().x << "  " << getPosAbs().y << "    |  parent : " << m_parent << " \n";

    // si on a pas définie une taille pour ce groupe alors son global BB c'est celui des enfants
    if ( m_taille == sf::Vector2f (0,0) ){
        // et on cherche les minimums et maximums parmis les enfants
        float minX = 5000;
        float maxX = -5000;
        float minY = 5000;
        float maxY = -5000;

        for ( ptr enfant : m_enfants ) {
            sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
            if (rect.left< minX) minX = rect.left;
            if (rect.left + rect.width > maxX ) maxX = rect.left + rect.width ;
            if (rect.top < minY) minY = rect.top;
            if (rect.top + rect.height > maxY ) maxY = rect.top + rect.height ;
        }
        result = { minX + getPosAbs().x , minY + getPosAbs().y , maxX-minX , maxY-minY  };
        //std::cout << ">>> A\n";

    // sinon on revois la taille déinife m_taille
    } else {
        //std::cout << ">>> B\n";
        result = sf::FloatRect  ( getPosAbs().x, getPosAbs().y, m_taille.x , m_taille.y );
    }
/*
std::cout << "--------------> " ;

   std::cout << "\nresult.left : " << result.left;
   std::cout << "\nresult.top : " << result.top;
   std::cout << "\nresult.width : " << result.width;
   std::cout << "\nresult.height : " << result.height;
   std::cout << "\n";*/
    return { result };

}



/////////////////////////////////////////////////
sf::FloatRect
Groupe::getLocalBounds ( )const {

 sf::FloatRect result ( 0,0,0,0 );

    for ( ptr enfant : m_enfants ) {
        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
        if ( result.width < rect.left + rect.width )  result.width  = rect.left + rect.width;
        if ( result.height < rect.top + rect.height ) result.height = rect.top + rect.height;
    }

    result.width += 10; // pour laisser un espace
    result.height += 10; // pour laisser un espace

    return { result };

}



/////////////////////////////////////////////////
sf::Vector2f
Groupe::getSize ( )const{
    return { getLocalBounds ( ).width , getLocalBounds ( ).height};
};

/////////////////////////////////////////////////
void
Groupe::setSize ( sf::Vector2f taille ) {

    this->m_taille = taille;
};


/////////////////////////////////////////////////
void
Groupe::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const
{
    if ( not estVisible() ) return;


    // le transform du gadget combiné au transform parents (states).
    states.transform *= getTransform();

    // dessiner les gadgets enfants
    for ( const ptr& enfant : m_enfants )
        target.draw      ( *enfant , states );
}
} // fin namespace gui


