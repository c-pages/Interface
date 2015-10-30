#include "UI.h"
#include <Groupe.h>


namespace gui {
UI::UI()
: m_UI ( new Groupe() )
{

   // m_UI->setParent ( Gadget(this) );
    //ctor
}

UI::~UI()
{
    //dtor
}

void
UI::creerUI(){}

void
UI::ajouterUI( Gadget::ptr enfant ){
    m_UI->ajouter        ( enfant );
   // enfant->setParent   ( this );
}

//
//void
//UI::dessinerUI ( sf::RenderTarget& target, sf::RenderStates states ) const {
//    for ( ptr ui : m_UI )
//        target.draw      ( *ui , states );
//}

} // fin namespae
