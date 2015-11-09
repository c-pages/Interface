
/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include "Gadget.h"
#include <iostream>
#include <math.h>

namespace gui
{
/////////////////////////////////////////////////
Gadget::Gadget  ()
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( std::make_shared <Skin> () )
, m_style       ( std::make_shared <Style> () )
, m_actif       ( true )
, m_visible     ( true )
, m_aSupprimer  ( false )
, m_aActualiser ( true )
, m_id          ( 0 )
//, m_this        ( std::make_shared<Gadget>(this) )
//, m_DEBUG_SHAPE ( sf::RectangleShape () )
//, m_texte   ( new sf::Text () )
{

//    ////////////DEBUG/////////////
//    m_DEBUG_SHAPE.setFillColor (sf::Color (255,225,225,0));
//    m_DEBUG_SHAPE.setOutlineColor (sf::Color (255,225,225,255));
//    m_DEBUG_SHAPE.setOutlineThickness ( 2 );
//    ////////////DEBUG/////////////
}


/////////////////////////////////////////////////
Gadget::Gadget  ( std::shared_ptr<Style>    style )
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( std::make_shared <Skin>() )
, m_style       ( style )
, m_actif       ( true )
, m_visible     ( true )
, m_aSupprimer  ( false )
, m_aActualiser ( true )
, m_id          ( 0 )
{

}

/////////////////////////////////////////////////
Gadget::Gadget  ( std::shared_ptr <Skin>    skin )
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( skin )
, m_style       ( m_skin->fenetre )
, m_actif      ( true )
, m_visible     ( true )
, m_aSupprimer  ( false )
, m_aActualiser( true )
, m_id          ( 0 )
{

}


/////////////////////////////////////////////////
Gadget::~Gadget(){
    std::cout <<" DELETE GADGET\n";
    /** \todo  s'assurer que les gadgets se deletent quand on les retire de la scene...*/
}

/////////////////////////////////////////////////
sf::Vector2f
Gadget::getPosAbs (  )  const      {
    sf::Vector2f  result = getPosition ();
    if ( m_parent != nullptr )
        result += this->m_parent->getPosAbs();
    return result;
}


/////////////////////////////////////////////////
void
Gadget::ajouter ( ptr enfant ) {

    enfant->setID   ( m_enfants.size() );
    m_enfants.push_back(  enfant );
    enfant->m_parent = this;

}


/////////////////////////////////////////////////
unsigned int
Gadget::getID (  ) const {
    return m_id ;
};


/////////////////////////////////////////////////
void
Gadget::setID( unsigned int id ) {
    m_id = id;
}

/////////////////////////////////////////////////
void
Gadget::setSkin( std::shared_ptr<Skin>    skin ) {
    m_skin = skin ;
    majGeom( );
};


/////////////////////////////////////////////////
void
Gadget::setStyle( std::shared_ptr<Style>     style ) {
    m_style = style ;

//    m_style->print();
    majGeom( );
};


/////////////////////////////////////////////////
void
Gadget::aligner (  Gadget& cible , Alignements    align , float ecart  ){

    // distance a garder par rapport aux bords de la cible

    // le bounding box de la cible
    sf::FloatRect   rect_cible      = cible.getLocalBounds() ;

    // les axes d'alignements sur la cible
    float    cbl_gauche  = rect_cible.left;
    float    cbl_milieu  = rect_cible.left + rect_cible.width/2 ;
    float    cbl_droite  = rect_cible.left + rect_cible.width;

    float    cbl_haut    = rect_cible.top;
    float    cbl_centre  = rect_cible.top + rect_cible.height/2;
    float    cbl_bas     = rect_cible.top + rect_cible.height;

    // la boudning box du gadget
    sf::FloatRect   rect_this       = getLocalBounds() ;
//   std::cout << "\n-------------- ALIGNER ---------------- ";
//   std::cout << "\ncbl_gauche : " << cbl_gauche;
//   std::cout << "\ncbl_milieu : " << cbl_milieu;
//   std::cout << "\ncbl_droite : " << cbl_droite;
//   std::cout << "\ncbl_haut : " << cbl_haut;
//   std::cout << "\ncbl_centre : " << cbl_centre;
//   std::cout << "\ncbl_bas : " << cbl_bas;
//   std::cout << "\n";

    // les axes de la nouvelle position pour l'alignements du gadget sur la cible
    int gauche    =  std::round ( - rect_this.left  + cbl_gauche + ecart ) ;
    int milieu    =  std::round ( - (rect_this.left + rect_this.width/2 )    + cbl_milieu  ) ;
    int droite    =  std::round ( - (rect_this.left + rect_this.width   )    + cbl_droite  - ecart ) ;

    int haut      =  std::round ( - rect_this.top  + cbl_haut + ecart ) ;
    int centre    =  std::round ( - (rect_this.top + rect_this.height/2 )    + cbl_centre ) ;
    int bas       =  std::round ( - (rect_this.top + rect_this.height   )    + cbl_bas  - ecart ) ;
/*
   std::cout << "\ngauche : " << gauche;
   std::cout << "\nmilieu : " << milieu;
   std::cout << "\ndroite : " << droite;
   std::cout << "\nhaut : " << haut;
   std::cout << "\ncentre : " << centre;
   std::cout << "\nbas : " << bas;
   std::cout << "\n";*/
    // et donc on combine en fonction de l'alignement choisi
    switch ( align ) {
        case Alignements::Haut_Gche:{   setPosition( gauche , haut );   }break;
        case Alignements::Haut_Mili:{   setPosition( milieu , haut );   }break;
        case Alignements::Haut_Drte:{   setPosition( droite , haut );   }break;
        case Alignements::Ctre_Gche:{   setPosition( gauche , centre ); }break;
        case Alignements::Ctre_Mili:{   setPosition( milieu , centre ); }break;
        case Alignements::Ctre_Drte:{   setPosition( droite , centre ); }break;
        case Alignements::Bas_Gche:{    setPosition( gauche , bas );    }break;
        case Alignements::Bas_Mili:{    setPosition( milieu , bas );    }break;
        case Alignements::Bas_Drte:{    setPosition( droite , bas );    }break;
        case Alignements::Libre:{}break;
        default:{}break;
    }
}



/////////////////////////////////////////////////
void
Gadget::demander_mettreAuDessus( )
{
    m_parent->mettreAuDessus(  m_id );
}





/////////////////////////////////////////////////
void
Gadget::mettreAuDessus( unsigned int ID )
{
    // on cherche l'id du gadget à mannipuler
    ptr     thisPtr = nullptr;
    for ( auto cible : m_enfants )
        if ( cible->getID() == ID )
            thisPtr = cible;

    // on le deplace dans le tableau pour le mettre à la fin
    if ( thisPtr != nullptr ){
        m_enfants.erase ( m_enfants.begin() + ID );
        m_enfants.push_back ( thisPtr );
    }

    // on actualise les id de la liste
    int i = 0;
    for ( auto cible : m_enfants )
        cible->setID(i++);


}

/*
///////////////////////////////////////////////////
//void
//Gadget::aligner (  sf::RenderWindow*   cible , Alignements    align  = Alignements::Ctre_Mili , float ecart = 0 );
//
//    // distance a garder par rapport aux bords de la cible
//
//    // le bounding box de la cible
//    sf::FloatRect   rect_cible      = cible.getLocalBounds() ;
//
//    // les axes d'alignements sur la cible
//    float    cbl_gauche  = rect_cible.left;
//    float    cbl_milieu  = rect_cible.left + rect_cible.width/2 ;
//    float    cbl_droite  = rect_cible.left + rect_cible.width;
//
//    float    cbl_haut    = rect_cible.top;
//    float    cbl_centre  = rect_cible.top + rect_cible.height/2;
//    float    cbl_bas     = rect_cible.top + rect_cible.height;
//
//    // la boudning box du gadget
//    sf::FloatRect   rect_this       = getLocalBounds() ;
//
//
//    // les axes de la nouvelle position pour l'alignements du gadget sur la cible
//    int gauche    =  std::round ( - rect_this.left  + cbl_gauche + ecart ) ;
//    int milieu    =  std::round ( - (rect_this.left + rect_this.width/2 )    + cbl_milieu  ) ;
//    int droite    =  std::round ( - (rect_this.left + rect_this.width   )    + cbl_droite  - ecart ) ;
//
//    int haut      =  std::round ( - rect_this.top  + cbl_haut + ecart ) ;
//    int centre    =  std::round ( - (rect_this.top + rect_this.height/2 )    + cbl_centre ) ;
//    int bas       =  std::round ( - (rect_this.top + rect_this.height   )    + cbl_bas  - ecart ) ;
//
//    // et donc on combine en fonction de l'alignement choisi
//    switch ( align ) {
//        case Alignements::Haut_Gche:{   setPosition( gauche , haut );   }break;
//        case Alignements::Haut_Mili:{   setPosition( milieu , haut );   }break;
//        case Alignements::Haut_Drte:{   setPosition( droite , haut );   }break;
//        case Alignements::Ctre_Gche:{   setPosition( gauche , centre ); }break;
//        case Alignements::Ctre_Mili:{   setPosition( milieu , centre ); }break;
//        case Alignements::Ctre_Drte:{   setPosition( droite , centre ); }break;
//        case Alignements::Bas_Gche:{    setPosition( gauche , bas );    }break;
//        case Alignements::Bas_Mili:{    setPosition( milieu , bas );    }break;
//        case Alignements::Bas_Drte:{    setPosition( droite , bas );    }break;
//        case Alignements::Libre:{}break;
//        default:{}break;
//    }
//}
*/


/////////////////////////////////////////////////
bool
Gadget::contient ( float x, float y )
{
    sf::FloatRect rect  = getGlobalBounds();

//    ////////////DEBUG/////////////
//   // m_DEBUG_SHAPE.setPosition   ( rect.left  , rect.top      );
//    m_DEBUG_SHAPE.setSize       ( {rect.width , rect.height}   );
//    ////////////DEBUG/////////////



    // S'il est contenu alors on verif le parent pour savoir par exemple si
    // le gadget est visible dans la fenetre parent.
    if ( rect.contains( sf::Vector2f ( x , y ) ) ){
        if ( m_parent != 0 )    return  m_parent->contient ( x, y );
        else                    return  true;
    } else return false;

};


/////////////////////////////////////////////////
void
Gadget::actualiser ( float deltaT )
{
    // Supprimer les gadgets enfants en attente de suppression
    for ( int i = m_enfants.size()-1 ; i >= 0; i-- )
        if ( m_enfants[i]->aSupprimer() )
            m_enfants.erase ( m_enfants.begin() + i );

//        std::cout << "------------------------------\n";
    // Actualiser les enfants
    for ( ptr enfant : m_enfants ){
//        std::cout << "-> enfant->estVisible() : " << enfant->estVisible() << "\n";
        if ( enfant->estVisible() and enfant->estActif() )
            enfant->actualiser ( deltaT );
    }

}

/////////////////////////////////////////////////
void
Gadget::traiter_evenements ( const sf::Event& event )
{

    if ( not estVisible() and not estActif() ) return;

    Action::traiter_evenements   (event);

    // les evenements des gadgets enfants
    for ( ptr enfant : m_enfants )
        enfant->traiter_evenements ( event );
}

/////////////////////////////////////////////////
void
Gadget::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const
{
    // le transform du gadget combiné au transform parents (states).
    states.transform *= getTransform();


//    ////////////DEBUG/////////////
//    target.draw      ( m_DEBUG_SHAPE  );
//    ////////////DEBUG/////////////



    // dessiner les gadgets enfants
    for ( const ptr& enfant : m_enfants )
        if ( enfant->estVisible() )
            target.draw      ( *enfant , states );

}

} // fin du namespace gui
