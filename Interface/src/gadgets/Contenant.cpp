


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/Contenant.h"
#include "gadgets/Groupe.h"

namespace gui {

/////////////////////////////////////////////////
Contenant::Contenant( sf::RenderWindow  *     fenetre )
: Gadget()
, m_fenetreSFML     ( fenetre )
, m_bSliderVerti    ( false )
, m_bSliderHori     ( false )
, m_grpContenu      (  )
, m_UI              (  )
, m_spriteContenant ( new sf::Sprite ())
, m_posContenu      ( 0 , 0 )
, m_slideVerti      ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Verticale , m_skin) )
, m_slideHori       ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Horizontale, m_skin ) )
{
    // contenant et contenu
    m_grpContenu    = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_grpContenant  = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_grpContenant->ajouter (m_grpContenu);
    m_grpContenant->setParent( this );

    // UI
    m_UI            = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_UI->ajouter   ( m_slideVerti );
    m_UI->ajouter   ( m_slideHori );
    m_UI->setParent ( this );

}

/////////////////////////////////////////////////
Contenant::~Contenant()
{
    //dtor
}


/////////////////////////////////////////////////
sf::FloatRect
Contenant::getLocalBounds ( )const {
    sf::FloatRect result ( getPosition().x
                         , getPosition().y
                         , m_taille.x
                         , m_taille. y);
    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
Contenant::getGlobalBounds ( )const {

    sf::FloatRect result ( getPosAbs().x
                         , getPosAbs().y
                         , m_taille.x
                         , m_taille. y);

    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
Contenant::getContenuBounds ( ) const {

    sf::FloatRect result ( 0,0,0,0 );

    for ( ptr enfant : m_grpContenu->m_enfants ) {
        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
        if ( result.width < rect.left + rect.width )  result.width  = rect.left + rect.width;
        if ( result.height < rect.top + rect.height ) result.height = rect.top + rect.height;
    }

    result.width += 10; // pour laisser un espace
    result.height += 10; // pour laisser un espace

    return { result };
}


/////////////////////////////////////////////////
void
Contenant::traiter_evenements ( const sf::Event& event ) {

    m_UI->traiter_evenements( event );
    m_grpContenu->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}


/////////////////////////////////////////////////
void
Contenant::actualiser ( float deltaT )    {

    //  actualiser UI et contenu
    m_UI->actualiser        ( deltaT );
    m_grpContenu->actualiser( deltaT );

    //si on drag pas on a pas besoin d'actualiser donc  return
    if ( m_slideHori->isDragging() or m_slideVerti->isDragging() )
        m_besoinActua = true;
    if ( not m_besoinActua ) return;


    // on regarde si on a besoin des sliders
    m_bSliderHori = ( getContenuBounds().width > m_taille.x );
    m_bSliderVerti = ( getContenuBounds().height > m_taille.y );

    // on s'occupe des dimensions et positions des sliders et du contenu
    if ( m_bSliderHori and m_bSliderVerti ) {
        m_grpContenant->setSize ( {m_taille.x - m_slideVerti->getSize().x  , m_taille.y - m_slideHori->getSize().y}  );

        m_slideHori->setLongueurMax         ( m_taille.x - m_slideVerti->getSize().x );
        m_slideVerti->setLongueurMax        ( m_taille.y - m_slideHori->getSize().y );
        m_slideHori->setLongueurCourante    ( m_slideHori->getLongueurMax() / getContenuBounds().width * m_taille.x );
        m_slideVerti->setLongueurCourante   ( m_slideVerti->getLongueurMax() / getContenuBounds().height * m_taille.y );
    }
    else if ( m_bSliderHori ){
        m_grpContenant->setSize ( {m_taille.x  , m_taille.y - m_slideHori->getSize().y}  );

        m_slideHori->setLongueurMax         ( m_taille.x );
        m_slideHori->setLongueurCourante    ( m_taille.x / getContenuBounds().width * m_taille.x );
    }
    else if ( m_bSliderVerti ) {
        m_grpContenant->setSize ( {m_taille.x - m_slideVerti->getSize().x  , m_taille.y}  );
        m_slideVerti->setLongueurMax        ( m_taille.y );
        m_slideVerti->setLongueurCourante   ( m_taille.y / getContenuBounds().height * m_taille.y );
    }

    // On positionne les sliders
    m_slideHori->setPosition                ( 0 , m_taille.y - m_slideHori->getSize().y  );
    m_slideVerti->setPosition               ( m_taille.x - m_slideVerti->getSize().x , 0 );

    // On positionne le groupe du contenu
    m_posContenu.x = m_slideHori->getSlidePos().x  / m_slideHori->getLongueurMax()  * getContenuBounds().width;
    m_posContenu.y = m_slideVerti->getSlidePos().y / m_slideVerti->getLongueurMax() * getContenuBounds().height;

    m_grpContenu->setPosition ( -m_posContenu.x , -m_posContenu.y );

    // on dimenssione l'UI
    m_UI->setSize           ( m_taille );

    // reinitialisation  du besoin d'actualiser
    m_besoinActua = false;
}


/////////////////////////////////////////////////
void
Contenant::ajouter( ptr enfant )   {
    m_grpContenu->ajouter ( enfant );
}




/////////////////////////////////////////////////
void
Contenant::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();


   // les dimemsions pour l'affichage du contenu
    sf::Vector2i    tailleTexture, tailleAffiche;
    tailleTexture.x = getContenuBounds().left   + getContenuBounds().width + 1;
    tailleTexture.y = getContenuBounds().top    + getContenuBounds().height + 1;
    tailleAffiche.x = m_taille.x;
    tailleAffiche.y = m_taille.y;
    if ( m_bSliderHori )
        tailleAffiche.y -= m_slideHori->getSize().y;
    if ( m_bSliderVerti )
        tailleAffiche.x -= m_slideVerti->getSize().x;


    // la texture dans laquelle on va dessiner les éléments contenus
    sf::RenderTexture       texture;
    if ( texture.create   ( tailleTexture.x  , tailleTexture.y   ) ) {

        // dessiner le contenu dans la texture
        texture.clear     ( m_skin->invisible->fnd_couleur );
        texture.draw      ( *m_grpContenu );
        texture.display   ( );

        // Appliquer la texture au sprite qui va l'afficher.
        m_spriteContenant->setTexture    ( texture.getTexture() );
        m_spriteContenant->setTextureRect( sf::IntRect( 0 , 0 , tailleAffiche.x , tailleAffiche.y ) );
    }

    //dessiner le sprite du contenu.
    target.draw      ( *m_spriteContenant , states );

    //dessiner les boutons drag
    if ( m_bSliderHori )
        target.draw      ( *m_slideHori , states );
    if ( m_bSliderVerti )
        target.draw      ( *m_slideVerti , states );


}


} // fin namespace








