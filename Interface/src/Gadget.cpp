
/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include "Gadget.h"
#include <iostream>

namespace gui
{
/////////////////////////////////////////////////
Gadget::Gadget  ()
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( std::make_shared <Skin> () )
, m_style       ( Style () )
, m_enable      ( true )
, m_aSupprimer  ( false )
, m_besoinActua( true )
//, m_texte   ( new sf::Text () )
{ }


/////////////////////////////////////////////////
Gadget::Gadget  ( Style    style )
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( std::make_shared <Skin>() )
, m_style       ( style )
, m_enable      ( true )
, m_aSupprimer  ( false )
, m_besoinActua( true )
{ }

/////////////////////////////////////////////////
Gadget::Gadget  ( std::shared_ptr <Skin>    skin )
: m_parent      ( 0 )
, m_enfants     ( 0 )
, m_skin        ( skin )
, m_style       ( *m_skin->fenetre )
, m_enable      ( true )
, m_aSupprimer  ( false )
, m_besoinActua( true )
{ }


/////////////////////////////////////////////////
Gadget::~Gadget(){
    std::cout <<" DELETE GADGET\n";
    /** \todo  s'assurer que les gadgets se deletent quand on les retire de la scene...*/
}

/////////////////////////////////////////////////
sf::Vector2f
Gadget::getPosAbs (  )        {
    sf::Vector2f  result = getPosition ();
    if ( m_parent != 0) result += this->m_parent->getPosAbs();
    return result ;
}


/////////////////////////////////////////////////
void
Gadget::ajouter ( ptr enfant ) {
    m_enfants.push_back(  enfant );
    enfant->m_parent = this;
    std::cout << "enfant ajout�, enfants: " << m_enfants.size() << "\n";
};


/////////////////////////////////////////////////
void
Gadget::aligner (  Gadget& cible , Alignements    align ){

    // distance a garder par rapport aux bords de la cible
    /// \todo rendre ecart accessible
    float           ecart           = 3;

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

    // les axes de la nouvelle position pour l'alignements du gadget sur la cible
    float gauche    = - rect_this.left  + cbl_gauche + ecart;
    float milieu    = - (rect_this.left + rect_this.width/2 )    + cbl_milieu ;
    float droite    = - (rect_this.left + rect_this.width   )    + cbl_droite  - ecart;

    float haut      = - rect_this.top  + cbl_haut + ecart;
    float centre    = - (rect_this.top + rect_this.height/2 )    + cbl_centre;
    float bas       = - (rect_this.top + rect_this.height   )    + cbl_bas  - ecart;

    // et donc on combine en fonction de l'alignement choisi
    switch ( align ) {
        case Alignements::Haut_Gche:{
            setPosition( gauche , haut );
        }break;
        case Alignements::Haut_Mili:{
            setPosition( milieu , haut );
        }break;
        case Alignements::Haut_Drte:{
            setPosition( droite , haut );
        }break;
        case Alignements::Ctre_Gche:{
            setPosition( gauche , centre );
        }break;
        case Alignements::Ctre_Mili:{
            setPosition( milieu , centre );
        }break;
        case Alignements::Ctre_Drte:{
            setPosition( droite , centre );
        }break;
        case Alignements::Bas_Gche:{
            setPosition( gauche , bas );
        }break;
        case Alignements::Bas_Mili:{
            setPosition( milieu , bas );
        }break;
        case Alignements::Bas_Drte:{
            setPosition( droite , bas );
        }break;
        case Alignements::Libre:{
        }break;
        default:{}break;
    }
}

/////////////////////////////////////////////////
bool
Gadget::contient ( float x, float y )
{
    /////////////////////////////////////////////////
    /// \todo ici c'est l'bordel, entre local, global et les transformations,
    /// une rotation sur un bouton et la zone de clique ne suivait pas.
    /////////////////////////////////////////////////

    getTransform();


    // la bouding box globale du gadget
    sf::FloatRect rect = getGlobalBounds();

    // S'il est contenu alors on verif le parent pour savoir par exemple si
    // le gadget est en vue dans la fenetre parent.
    if ( rect.contains( sf::Vector2f ( x , y ) ) ){
        if ( m_parent != 0 )
            return   m_parent->contient ( x, y );
        else return true;
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

    // Actualiser les enfants
    for ( ptr enfant : m_enfants )
        enfant->actualiser ( deltaT );

}

/////////////////////////////////////////////////
void
Gadget::traiter_evenements ( const sf::Event& event )
{
    // les evenements des gadgets enfants
    for ( ptr enfant : m_enfants )
        enfant->traiter_evenements ( event );
}

/////////////////////////////////////////////////
void
Gadget::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const
{
    // le transform du gadget combin� au transform parents (states).
    states.transform *= getTransform();

    // dessiner les gadgets enfants
    for ( const ptr& enfant : m_enfants )
        target.draw      ( *enfant , states );
}

} // fin du namespace gui
