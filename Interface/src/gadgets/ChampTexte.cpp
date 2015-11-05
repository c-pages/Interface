
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <ChampTexte.h>
#include <gadgets/Label.h>
#include <gadgets/BoutonEncoche.h>
#include <gadgets/Groupe.h>



namespace gui{


/////////////////////////////////////////////////
ChampTexte::ChampTexte  ( sf::Vector2f              taille
                        , std::shared_ptr<Skin>     skin   )
: m_grpUI   ( new Groupe ( ) )
, m_lbl     ( new Label ( "Champ" ) )
, m_btn     ( new BoutonEncoche ( skin , false ) )
, m_curseur ( sf::RectangleShape ())
, m_clignot ( false )
, m_timerClignot ()
{

//m_timerClignot.restart();

    m_skin = skin;

    m_btn->setSize ( taille );




    initUI();
    initLocalSkin ();

    m_curseur.setSize               ( {0 , 20} );
    m_curseur.setOutlineColor       ( m_skin->lblCourant->txt_couleur );
    m_curseur.setOutlineThickness   ( m_skinBtn->btnRepos->lgn_epaisseur );


//    m_lbl->setSkin  ( m_skinBtn );
    m_lbl->setStyle ( m_skin->lblCourant );
    m_btn->setSkin  ( m_skinBtn );

    // integration dans le groupe UI
    m_grpUI->setParent ( this );
    m_grpUI->ajouter   ( m_btn );
    m_grpUI->ajouter   ( m_lbl );

}


/////////////////////////////////////////////////
ChampTexte::~ChampTexte()
{
    //dtor
}


/////////////////////////////////////////////////
std::string
ChampTexte::getTexte()
{
    return m_lbl->getTexte();
}


/////////////////////////////////////////////////
void
ChampTexte::setTexte ( std::string txt )
{
    m_lbl->setTexte( txt );
}



/////////////////////////////////////////////////
void
ChampTexte::initUI()
{
    m_btn->lier ( Evenements::onBtn_changeEtat , [this]() {

        // l'état du boutonEncoche : true: en stock une verion du texte du lbl pour si annulation .
        if ( m_btn->estCoche() ) {

            // clock pour clignotements du curseur
            m_timerClignot.restart();
            m_clignot = true;

            // sauvegarde du texte pour si annulation
            m_texteBack = m_lbl->getTexte();

            // liaison de l'action pour quiter la saisie
            m_btn->lier ( Evenements::onBtnG_PressDehors , [this]() {
                m_btn->setCoche(false);
                // l'état du boutonEncoche : true: en stock une verion du texte du lbl pour si annulation .
                m_btn->delier ( Evenements::onBtnG_PressDehors   );
            });
//


        }

    });



}


/////////////////////////////////////////////////
sf::FloatRect
ChampTexte::getLocalBounds ( ) const{
    return  m_btn->getLocalBounds ( );
}


/////////////////////////////////////////////////
sf::FloatRect
ChampTexte::getGlobalBounds ( ) const
{

    return  m_btn->getGlobalBounds ( );
}



/////////////////////////////////////////////////
void
ChampTexte::traiter_evenements ( const sf::Event& event )
{
    m_grpUI->traiter_evenements ( event );

    //if ( Bouton::ms_btnPress != m_btn )  m_btn->setCoche(false);


    // gestion de la saisie de texte
    if ( m_btn->estCoche()
    and  event.type == sf::Event::TextEntered
        /* and  event.text.unicode < 128*/ ) {

        // le texte avant modif dans le label
        std::string txt = m_lbl->getTexte() ;

        // touche Retour arriere : effacer arriere  //////////////////////////////
        if ( event.text.unicode == 8 )  {
            // si le champ est vide on retourne.
            if ( txt.size()==0 ) return;

            // sinon on retire une lettre et on declenche l'action
            txt.erase ( txt.size()-1 , 1);
            m_lbl->setTexte( txt  );
            declencher( onCha_ChangeValeur );
        }
        // touche Entrée : Valider  //////////////////////////////
        else if ( event.text.unicode == 13 )  {
            declencher( onCha_ValideValeur );
            m_btn->setCoche( false);
        }
        // touche Echappe : Annuler  //////////////////////////////
        else if ( event.text.unicode == 27 )  {
            m_lbl->setTexte( m_texteBack  );
            m_btn->setCoche( false);
        }
        // les autres touches  //////////////////////////////
        else {

            m_lbl->setTexte( txt + static_cast<char>(event.text.unicode)  );

            // s'il ne reste plus de place pour ecrire on retourne
            float largeurTexte = m_lbl->getSFTexte()->findCharacterPos 	(  m_lbl->getTexte().size() ).x;

            std::cout << " -> largeurTexte : " << largeurTexte << "\n";

            if ( largeurTexte > m_btn->getSize().x - 1 )
                m_lbl->setTexte( txt );

            // on déclenche et on ecrit.
            declencher( onCha_ChangeValeur );
        }

        // clock pour clignotements du curseur
        m_timerClignot.restart();
        m_clignot = true;

        // et on demande une mise a jour du gadget.
        demanderActualisation();
    }

}
////////////////////////////////////////////////////
void
ChampTexte::setSkin( std::shared_ptr<Skin>    skin )
{

}




/////////////////////////////////////////////////
void
ChampTexte::initLocalSkin (){

    m_skinBtn =   std::make_shared<gui::Skin> () ;

    //sf::Color transparent =  sf::Color  ( 255,255,255 );

    //// BOUTON REPOS ///////////////////////////////////
    m_skinBtn->btnRepos->txt_style         = sf::Text::Style::Regular ;
    m_skinBtn->btnRepos->txt_taille        = m_skin->btnRepos->txt_taille;
    m_skinBtn->btnRepos->txt_couleur       = sf::Color::Black;
    m_skinBtn->btnRepos->lgn_epaisseur     = 1;
    m_skinBtn->btnRepos->lgn_couleur       = sf::Color  ( 255,255,255 , 20 );
    m_skinBtn->btnRepos->fnd_couleur       = sf::Color  ( 255,255,255 , 125 );
    m_skinBtn->btnRepos->fnd_texture       = sf::Texture ();
    m_skinBtn->btnRepos->align             = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnRepos->ajust             = gui::Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    m_skinBtn->btnSurvol->txt_style        = sf::Text::Style::Regular;
    m_skinBtn->btnSurvol->txt_taille       = m_skin->btnSurvol->txt_taille;
    m_skinBtn->btnSurvol->txt_couleur      = sf::Color::Black;
    m_skinBtn->btnSurvol->lgn_epaisseur    = 1;
    m_skinBtn->btnSurvol->lgn_couleur      = sf::Color  ( 255,255,255 , 20 );
    m_skinBtn->btnSurvol->fnd_couleur      = sf::Color  ( 255,255,255 , 200 );
    m_skinBtn->btnSurvol->fnd_texture      = sf::Texture ();
    m_skinBtn->btnSurvol->align            = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnSurvol->ajust            = gui::Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    m_skinBtn->btnPress->txt_style         = sf::Text::Style::Regular;
    m_skinBtn->btnPress->txt_taille        = m_skin->btnPress->txt_taille;
    m_skinBtn->btnPress->txt_couleur       = sf::Color::Black;
    m_skinBtn->btnPress->lgn_epaisseur     = 1;
    m_skinBtn->btnPress->lgn_couleur       = sf::Color  ( 100,100,100 , 255 );
    m_skinBtn->btnPress->fnd_couleur       = sf::Color  ( 255,255,255 , 255 );
    m_skinBtn->btnPress->fnd_texture       = sf::Texture ();
    m_skinBtn->btnPress->align             = gui::Alignements::Ctre_Mili;
    m_skinBtn->btnPress->ajust             = gui::Ajustements::Sans;

}





/////////////////////////////////////////////////
void
ChampTexte::actualiser ( float deltaT )
{
    // clignotements
    if (m_btn->estCoche() )
        if ( m_timerClignot.getElapsedTime().asSeconds()>.5 ) {
            m_clignot = not m_clignot;
            m_timerClignot.restart();
        }


    m_grpUI->actualiser ( deltaT );

    if ( not m_aActualiser ) return;

    // on aligne le curseur sur le fin du texte
    m_curseur.setPosition ( m_lbl->getSFTexte()->findCharacterPos 	(  m_lbl->getTexte().size() )  );
    m_curseur.move( 1 , 0 );

}


/////////////////////////////////////////////////
void
ChampTexte::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
    if ( not m_visible ) return;


    states.transform *= getTransform();
    target.draw         ( *m_grpUI , states );
//    target.draw         ( *m_lbl , states );

    for ( ptr enfant : m_enfants )
        target.draw ( *enfant , states );

    if (m_btn->estCoche() )
        if ( m_clignot )
            target.draw ( m_curseur , states );



}



} // fin namespace


