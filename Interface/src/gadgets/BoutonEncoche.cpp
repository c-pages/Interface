
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/BoutonEncoche.h>
#include <gadgets/Image.h>


namespace gui {

/////////////////////////////////////////////////
BoutonEncoche::BoutonEncoche()
: Bouton    (  )
, m_actif     ( false )
, m_imgCoche  ( new Image )
//, m_bordure   ( 2 )
{

   init();
}



/////////////////////////////////////////////////
BoutonEncoche::BoutonEncoche  ( std::shared_ptr<Skin>  skin
                             , bool      actif )
: Bouton    ( skin )
, m_actif     ( actif )
, m_imgCoche  ( new Image () )
//, m_bordure   ( 1 )
{
    m_imgCoche->setFillColor(m_style->txt_couleur);
    init();
}


/////////////////////////////////////////////////
BoutonEncoche::~BoutonEncoche()
{
    //dtor
}


/////////////////////////////////////////////////
void
BoutonEncoche::majGeom()
{
    Bouton::majGeom();
    m_imgCoche->setSize ( m_fond->getSize() - sf::Vector2f ( m_bordure *2 , m_bordure *2 ) );
    m_imgCoche->aligner ( *m_fond );
}


/////////////////////////////////////////////////
void
BoutonEncoche::init( )    {

    // init la valeur de l'espace en coche et bord;
    m_bordure = 1;

    // la fonction toggle de l'état du bouton
    m_fctToggle = [this](){
        m_actif = not m_actif;
        declencher( Evenements::onBtn_changeEtat );
    };

    // liaison entre l'evenement sourisGaucheRelache et la fonction toggle.
    this->lier( Evenements::onBtnG_Relache , m_fctToggle );

}

/////////////////////////////////////////////////
void
BoutonEncoche::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    if ( not m_visible ) return;


    states.transform *= getTransform();

    // on dessine le bouton
    target.draw      ( *m_fond      , states );

    // si actif on dessine la coche
    if ( m_actif )
        target.draw      ( *m_imgCoche  , states );

    for ( ptr enfant : m_enfants )
        target.draw      ( *enfant , states );
}


} // fin namespace gui
