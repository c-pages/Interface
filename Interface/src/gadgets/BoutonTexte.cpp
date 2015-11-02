

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/BoutonTexte.h"
#include "gadgets/Label.h"
#include "gadgets/Image.h"

namespace gui {

/////////////////////////////////////////////////
BoutonTexte::BoutonTexte ( std::string    texte )
: m_lblTexte  ( new Label ( texte ) )
{
    init ();
}


/////////////////////////////////////////////////
BoutonTexte::BoutonTexte(std::shared_ptr<Skin> skin ,    std::string    texte )
: Bouton      (  skin )
, m_lblTexte  (  new Label ( texte , skin->btnRepos ) )
{
    init ();
}


/////////////////////////////////////////////////
void
BoutonTexte::init ()
{
    // init la valeur de l'espace en coche et bord;
    m_bordure = 2;

    // Mise a jour des formes du gadget.
    majGeom( );
}

/////////////////////////////////////////////////
BoutonTexte::~BoutonTexte() {
    std::cout << " DESTRUCTEUR BoutonTexte : " <<  m_enfants.size()    << "\n";
}


/////////////////////////////////////////////////
void
BoutonTexte::setSize   ( sf::Vector2f   taille )   {
    m_fond->setSize( taille );
 //   m_lblTexte->aligner ( *m_fond , m_style->align );
}


/////////////////////////////////////////////////
void
BoutonTexte::ajusterAuTexte   (){
    sf::FloatRect  rectTxt  ( m_lblTexte->getLocalBounds() );
    m_fond->setSize( { rectTxt.width + 2* m_bordure, rectTxt.height + 2* m_bordure } );
   // m_lblTexte->aligner(*m_fond , m_style->align );
};


/////////////////////////////////////////////////
void
BoutonTexte::setSkin( std::shared_ptr<Skin> skin )    {
    Bouton::setSkin( skin );
    m_lblTexte->setStyle( skin->btnRepos );
    majGeom() ;
}

/////////////////////////////////////////////////
void
BoutonTexte::majGeom( )    {

    // mise a jour du style du bouton
    Bouton::majGeom ( );

    // mise a jour du style du texte
    m_lblTexte->setStyle    ( m_style );
    //  m_lblTexte->aligner     ( *m_fond , m_style->align );

}


/////////////////////////////////////////////////
void
BoutonTexte::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    states.transform *= getTransform();

    target.draw ( *m_fond , states );
    target.draw ( *m_lblTexte , states );

}



} // fin namespace gui


