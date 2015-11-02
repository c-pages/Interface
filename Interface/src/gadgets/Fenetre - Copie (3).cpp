
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/Fenetre.h>
#include <../GUI.h>




namespace gui {

/////////////////////////////////////////////////
Fenetre::Fenetre( sf::RenderWindow  *     fenetre )
: m_fenetreSFML     ( fenetre )
, m_grpUI           ( std::make_shared<Groupe>() )
, m_lblTitre        ( std::make_shared<Label>( "Titre" ) )
, m_btnFermer       ( std::make_shared<BoutonTexte>( "X" ) )
, m_contenant       ( std::make_shared<Contenant>( fenetre ) )
, m_fond            ( std::make_shared<Image>( ) )
{
    m_grpUI->ajouter ( m_lblTitre );
    m_grpUI->ajouter ( m_btnFermer );
    m_contenant->setParent ( this );
//    m_grpUI->ajouter ( m_lblTitre );
    //ctor
}

/////////////////////////////////////////////////
Fenetre::~Fenetre()
{
    //dtor
}



/////////////////////////////////////////////////
void
Fenetre::setTitre ( std::string titre )
{
    m_lblTitre->setTexte( titre ) ;
};


/////////////////////////////////////////////////
void
Fenetre::traiter_evenements ( const sf::Event& event ) {

    m_grpUI->traiter_evenements( event );
    m_contenant->traiter_evenements( event );

    Action::traiter_evenements( event );
    Gadget::traiter_evenements( event );

}


/////////////////////////////////////////////////
void
Fenetre::actualiser ( float deltaT )    {

    // Actualiser UI et contenu
    m_grpUI->actualiser        ( deltaT );
    m_contenant->actualiser( deltaT );

}


/////////////////////////////////////////////////
void
Fenetre::ajouter( ptr enfant )   {
    m_contenant->ajouter ( enfant );
}




/////////////////////////////////////////////////
void
Fenetre::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    // appliquer les transformations de la fenêtre au states
    states.transform *= getTransform();

    //dessiner le sprite du contenu.
    target.draw      ( *m_grpUI     , states );
    target.draw      ( *m_contenant , states );

   // les dimemsions pour l'affichage du contenu
//    sf::Vector2i    tailleTexture, tailleAffiche;
//    tailleTexture.x = getContenuBounds().left   + getContenuBounds().width + 1;
//    tailleTexture.y = getContenuBounds().top    + getContenuBounds().height + 1;
//    tailleAffiche.x = m_taille.x;
//    tailleAffiche.y = m_taille.y;
//
//    if ( m_bSliderHori )    tailleAffiche.y -= m_slideHori->getSize().y;
//    if ( m_bSliderVerti )   tailleAffiche.x -= m_slideVerti->getSize().x;
//
//
//    // la texture dans laquelle on va dessiner les éléments contenus
//    sf::RenderTexture       texture;
//    if ( texture.create   ( tailleTexture.x  , tailleTexture.y   ) ) {
//
//        // dessiner le contenu dans la texture
//        texture.clear     ( m_skin->invisible->fnd_couleur );
//        texture.draw      ( *m_grpContenu );
//        texture.display   ( );
//
//        // Appliquer la texture au sprite qui va l'afficher.
//        m_spriteContenant->setTexture    ( texture.getTexture() );
//        m_spriteContenant->setTextureRect( sf::IntRect( 0 , 0 , tailleAffiche.x , tailleAffiche.y ) );
//    }
//
//    //dessiner le sprite du contenu.
//    target.draw      ( *m_spriteContenant , states );
//
//    //dessiner les boutons drag
//    if ( m_bSliderHori )
//        target.draw      ( *m_slideHori , states );
//    if ( m_bSliderVerti )
//        target.draw      ( *m_slideVerti , states );


}

} // fin namespace
