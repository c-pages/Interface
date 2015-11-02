


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
, m_grpUI              (  )
, m_spriteContenant ( new sf::Sprite ())
, m_posContenu      ( 0 , 0 )
, m_slideVerti      ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Verticale , m_skin) )
, m_slideHori       ( std::make_shared<BoutonSlide> ( fenetre, Orientation::Horizontale, m_skin ) )
, m_tailleTexture   ({ 1 , 1})
, m_tailleAffiche   ({ 1 , 1})
{
    // contenant et contenu
    m_grpContenu    = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_grpContenant  = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_grpContenant->ajouter (m_grpContenu);
    m_grpContenant->setParent( this );

    // UI
    m_grpUI            = std::shared_ptr<Groupe>       ( new Groupe   ( ) );
    m_grpUI->ajouter   ( m_slideVerti );
    m_grpUI->ajouter   ( m_slideHori );
    m_grpUI->setParent ( this );

  //  actualiser ( 1 );

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
//sult.height += 10; // pour laisser un espace

    //float minX = 5000;
    float maxX = -5000;
   // float minY = 5000;
    float maxY = -5000;

    for ( ptr enfant : m_grpContenu->m_enfants ) {
        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;
        //if (rect.left< minX) minX = rect.left;
        if (rect.left + rect.width > maxX ) maxX = rect.left + rect.width ;
        //if (rect.top < minY) minY = rect.top;
        if (rect.top + rect.height > maxY ) maxY = rect.top + rect.height ;

    }
    result = { 0, 0, maxX , maxY  };

    // pour laisser un espace sur les cotés
    result.width    += 10;
    result.height   += 20;
    return { result };
}


/////////////////////////////////////////////////
void
Contenant::traiter_evenements ( const sf::Event& event ) {

    m_grpUI->traiter_evenements( event );
    m_grpContenu->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}


/////////////////////////////////////////////////
void
Contenant::actualiser ( float deltaT )    {


    // Actualiser UI et contenu
    m_grpUI->actualiser      ( deltaT );
    m_grpContenu->actualiser ( deltaT );

    // Si on drag, on a besoin d'actualiser
    if ( m_slideHori->isDragging() or m_slideVerti->isDragging() )
        m_besoinActua = true;

    // si pas besoin d'acttua on retourne
    if ( not m_besoinActua ) return;





    // les tailles des textures et du sprite pour rendu
    m_tailleTexture.x = getContenuBounds().left   + getContenuBounds().width  + 2;
    m_tailleTexture.y = getContenuBounds().top    + getContenuBounds().height + 2;
    m_tailleAffiche.x = m_taille.x;
    m_tailleAffiche.y = m_taille.y;

    if ( m_bSliderHori )    m_tailleAffiche.y -= m_slideHori->getSize().y;
    if ( m_bSliderVerti )   m_tailleAffiche.x -= m_slideVerti->getSize().x;

    // on verifie si on a besoin des sliders
    m_bSliderHori   = ( getContenuBounds().width    >   m_taille.x );
    m_bSliderVerti  = ( getContenuBounds().height   >   m_taille.y );







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
    m_grpUI->setSize           ( m_taille );

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

    if ( not m_visible ) return;


    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();


    // la texture dans laquelle on va dessiner les éléments contenus
    sf::RenderTexture       texture;
    if ( texture.create   ( m_tailleTexture.x  , m_tailleTexture.y   ) ) {

        // dessiner le contenu dans la texture
        texture.clear     ( m_skin->invisible->fnd_couleur );
        texture.draw      ( *m_grpContenu );
        texture.display   ( );

        // Appliquer la texture au sprite qui va l'afficher.
        m_spriteContenant->setTexture    ( texture.getTexture() );
        m_spriteContenant->setTextureRect( sf::IntRect( 0 , 0 , m_tailleAffiche.x , m_tailleAffiche.y ) );
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








