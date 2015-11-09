
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/Bouton.h"
#include <iostream>
#include <../GUI.h>


namespace gui{

/////////////////////////////////////////////////
// Initialisation des statics
/////////////////////////////////////////////////
Gadget*     Bouton::ms_btnSurvol     = nullptr;
Gadget*     Bouton::ms_btnPress      = nullptr;


/////////////////////////////////////////////////
Bouton::Bouton  ( )
: Gadget    ( )
, m_etat    ( EtatBouton::repos )
, m_bIcone  ( false )
, m_icone   ( new Image () )
, m_fond    ( new Image () )
, m_bordure ( 0 )
{
    //    std::cout << "  --- Bouton --- Bouton ---\n";
    actualiser(1);
}


/////////////////////////////////////////////////
Bouton::Bouton  ( std::shared_ptr<Skin>    skin , sf::Vector2f taille )
: Gadget    ( skin )
, m_etat    ( EtatBouton::repos )
, m_bIcone  ( false )
, m_icone   ( new Image () )
, m_fond    ( new Image () )
, m_bordure ( 0 )
{
    setSize (taille);

    //  std::cout << "  --- Bouton --- Bouton ---\n";
    actualiser(1);
}


/////////////////////////////////////////////////
Bouton::~Bouton()
{ }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////
void
Bouton::setIcone   ( const sf::Texture*   texture ){

    m_bIcone = true;
    sf::Vector2f tailleTexture;

    m_icone->setTexture ( texture );
    m_icone->setSize    ( sf::Vector2f ( texture->getSize() ) );
    m_icone->aligner    ( *m_fond );

    m_aActualiser = true;
}


/////////////////////////////////////////////////
void
Bouton::setFillColor ( sf::Color color )   {
    m_fond->setFillColor   ( color ) ;
    m_aActualiser = true;
}


/////////////////////////////////////////////////
void
Bouton::setOutlineColor  ( sf::Color color ) {
    m_fond->setOutlineColor    ( color ) ;
    m_aActualiser = true;
}

/////////////////////////////////////////////////
void
Bouton::setOutlineThickness  ( float epaisseur )   {
    m_fond->setOutlineThickness    ( epaisseur ) ;
    m_aActualiser = true;
} ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////
void
Bouton::setSkin( std::shared_ptr<Skin>     skin ) {
    m_skin = skin ;
    majGeom( );
};


/////////////////////////////////////////////////
void
Bouton::setSize   ( sf::Vector2f   taille )   {
    //m_icone->setSize( taille );

    m_fond->setSize( taille );
    m_icone->aligner    ( *m_fond );
    m_aActualiser = true;
}


/////////////////////////////////////////////////
sf::Vector2f
Bouton::getSize ( )const {
    return m_fond->getSize();
    //return { m_fond->getLocalBounds().width , m_fond->getLocalBounds().height };
}


/////////////////////////////////////////////////
sf::FloatRect
Bouton::getLocalBounds ( ) const{
    sf::FloatRect result ( getPosition().x
                         , getPosition().y
                         , getSize().x
                         , getSize().y      );

//   std::cout << "\nresult.left : " ;
//   std::cout << "\n";
/*
    result.left     =  getPosition().x;
    result.top      =  getPosition().y;
    result.width    =  getSize().x;
    result.height   =  getSize().y;*/
/*
    for ( ptr enfant : m_enfants ) {

        sf::FloatRect rect  ( enfant->getLocalBounds() ) ;

        if ( result.left > rect.left  )   result.left = rect.left  ;
        if ( result.top > rect.top  )   result.top = rect.top   ;
        if ( result.width < rect.left + rect.width - result.left )   result.width = rect.left + rect.width - result.left ;
        if ( result.height < rect.top + rect.height - result.top )   result.height = rect.top + rect.height - result.top ;
    }*/
    return { result };
}


/////////////////////////////////////////////////
sf::FloatRect
Bouton::getGlobalBounds ( ) const{
    sf::FloatRect result( m_fond->getLocalBounds() );

    result.left     +=  getPosAbs().x;
    result.top      +=  getPosAbs().y;

    for ( ptr enfant : m_enfants ) {
        sf::FloatRect rect  ( enfant->getGlobalBounds() ) ;

        if ( result.left > rect.left  )   result.left = rect.left  ;
        if ( result.top > rect.top  )   result.top = rect.top   ;
        if ( result.width < rect.left + rect.width - result.left )   result.width = rect.left + rect.width - result.left ;
        if ( result.height < rect.top + rect.height - result.top )   result.height = rect.top + rect.height - result.top ;
    }
    return { result };
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////
void
Bouton::majGeom( )    {
    setOutlineColor     ( m_style->lgn_couleur );
    setOutlineThickness ( m_style->lgn_epaisseur  );

    if (m_style->aTexture()){
        m_fond->setTexture  ( &m_style->fnd_texture );
        setFillColor        ( sf::Color::White );
    }
    else setFillColor       ( m_style->fnd_couleur );
    m_aActualiser = true;
}



/////////////////////////////////////////////////
void
Bouton::gerer_etat( const sf::Event& event )
{

    // si le bouton est d�sactiv�, on sort apres avoir actualiser l'�tat
    if ( not m_actif ) {
        m_etat = EtatBouton::desactive;  // sinon �tat d�sactiv�
        return;
    }



    // si ce n'est pas un evenement souris on return
    if ( event.type != sf::Event::MouseButtonPressed
    and  event.type != sf::Event::MouseButtonReleased
    and  event.type != sf::Event::MouseMoved
    and  event.type != sf::Event::MouseEntered
    and  event.type != sf::Event::MouseLeft )
        return;



    //   test du survol en fonction tu type d'evenement ...
    bool survol;
    if ( event.type == sf::Event::MouseMoved )
            survol = contient( event.mouseMove.x    , event.mouseMove.y );
    else    survol = contient( event.mouseButton.x  , event.mouseButton.y );





    // Si on est le bouton press� on a l'�tat PRESS
    if ( ms_btnPress == this )
        m_etat = EtatBouton::press;

    // Sinon si c'est un autre bouton qui est press� on a l'�tat REPOS
    else if  ( ms_btnPress != nullptr )
         m_etat = EtatBouton::repos;

    // Sinon, si on survol le bouton
    else if ( survol ) {

        // et qu' on a press� le bouton on a l'�tat PRESS
        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) )
                m_etat = EtatBouton::press;

        // sinon on a juste l'�tat SURVOL
        else    m_etat = EtatBouton::survol;

    // Sinon, on survol pas le bouton, on a l'�tat REPOS
    } else   m_etat = EtatBouton::repos;





    //  si l'�tat a chang� alors on a besoin d'une actualisation ...
    if ( m_etat != m_etatBack )  m_aActualiser = true;
    // on garde en memoire l'�tat actuel pour verifer si changement la prochaine fois.
    m_etatBack = m_etat;

}



/////////////////////////////////////////////////
void
Bouton::gerer_declenchements( const sf::Event& event )
{

    // Double clique, on regarde si on reset le compteur de temps.
    if ( m_1erClick  &&     m_clock_dblClique.getElapsedTime().asMilliseconds () > 300 )
         m_1erClick = false;

    // on test le declenchement en fontion du type d'evenement
    switch ( event.type )  {

        /////////////////////////////////////////////////
        case sf::Event::MouseMoved : {
            test_declSurvol ( event );
        }break;

        /////////////////////////////////////////////////
        case sf::Event::MouseButtonPressed : {
            // si aucun bouton n'est press� on regarde comment on presse
            //if ( ms_btnPress == nullptr )
                test_declPress( event );

        } break;

        /////////////////////////////////////////////////
        case sf::Event::MouseButtonReleased : {
            // si on a press� sur ce bouton alors on regarde comment il est relach�
            //if ( ms_btnPress != this )
                test_declRelache( event );

        } break;

        ////////////////////////////////////////////////
        case sf::Event::MouseWheelMoved : {
            test_declRouletteSouris( event );
        } break;

        default :{ } break;

    } // fin switch ( event.type )



//    // ce truc c'est quand on a relach� le bouton hors de la fenetre
//    if ( not sf::Mouse::isButtonPressed(sf::Mouse::Left)
//    or   not sf::Mouse::isButtonPressed(sf::Mouse::Right)
//    or   not sf::Mouse::isButtonPressed(sf::Mouse::Middle) )
//    {
//        if ( ms_btnPress == this )
//            ms_btnPress = nullptr;
//    }


}




/////////////////////////////////////////////////
void
Bouton::test_declSurvol( const sf::Event& event ) {

    bool survol = Gadget::contient ( event.mouseMove.x , event.mouseMove.y );

    // si aucun bouton n'est press� on regarde si si on d�clenche...
    if ( ms_btnPress == nullptr ) {
        //   Si on survol le bouton ...
        if ( survol ) {
            // si repos alors on est en train de rentrer dans le bouton
            if ( m_etat == EtatBouton::repos )      declencher ( Evenements::onBtn_Entre );
        // Sinon on survole pas le bouton ...
        } else {
            // si repos alors on sort du bouton
            if ( m_etat == EtatBouton::survol )     declencher ( Evenements::onBtn_Sort );

        }
    } // fin if ( ms_btnPress == nullptr )

}


/////////////////////////////////////////////////
void
Bouton::test_declPress(  const sf::Event& event  ) {

    bool survol = Gadget::contient ( event.mouseButton.x , event.mouseButton.y );

    if ( survol )  {
        switch ( event.mouseButton.button ) {
                case  sf::Mouse::Button::Left:{         //   --------  Bouton Gauche --------
                    declencher ( Evenements::onBtnG_Press );
                }break;

                case  sf::Mouse::Button::Right:{        //   --------  Bouton Droit --------
                    declencher ( Evenements::onBtnD_Press );
                }break;

                case  sf::Mouse::Button::Middle:{       //   --------  Bouton Milieu --------
                    declencher ( Evenements::onBtnM_Press );
                }break;
                default : break;
        } // fin switch event.mouseButton.button

        // le bouton press� est celui ci
        ms_btnPress = this;

    }   //  fin if survol

}


/////////////////////////////////////////////////
void
Bouton::test_declRelache(  const sf::Event& event  ) {

    // si on a press� sur ce bouton on peut regarder comment on le relache
    if ( ms_btnPress == this ) {

        bool survol = Gadget::contient ( event.mouseButton.x , event.mouseButton.y );
        switch ( event.mouseButton.button ) {

            ///////    Bouton Gauche  //////////////
            case  sf::Mouse::Button::Left:{
                // si on est au dessus ...
                if ( survol ) {
                    // et qu'on a d�ja un 1er clique
                    if  ( m_1erClick ) {
                        // on d�clenche le DOUBLE CLIQUE
                        m_1erClick = false;
                        declencher ( Evenements::onBtnG_DblClique );
                    // sinon c'est notre premier clique
                    }  else {
                        // on initialise pour un double clique potentiel
                        m_1erClick = true;
                        m_clock_dblClique.restart();
                        //et on d�clenche RELACHE (simple clique).
                        declencher ( Evenements::onBtnG_Relache );
                    }
                // ... sinon on est a cot� du bouton, et on declenche RELACHE DEHORS
                } else   declencher ( Evenements::onBtnG_RelacheDehors );
            }break;


            ///////    Bouton Droit     //////////////
            case  sf::Mouse::Button::Right:{
                if ( survol )   declencher ( Evenements::onBtnD_Relache );
                else            declencher ( Evenements::onBtnD_RelacheDehors );
            }break;


            ///////    Bouton Milieu    //////////////
            case  sf::Mouse::Button::Middle:{
                if ( survol )   declencher ( Evenements::onBtnM_Relache );
                else            declencher ( Evenements::onBtnM_RelacheDehors );
            }break;

            default : break;


        } // fin switch event.mouseButton.button


        // plus de bouton press�
        ms_btnPress = nullptr;

    // sinon on a pas press� sur ce bouton
    }
     else {
        if ( event.mouseButton.button == sf::Mouse::Button::Left)
            declencher ( Evenements::onBtnG_PressDehors );

     }



}




/////////////////////////////////////////////////
void
Bouton::test_declRouletteSouris(  const sf::Event& event  ) {
    if ( Gadget::contient ( event.mouseButton.x , event.mouseButton.y ) ){
        if (event.mouseWheel.delta > 0 )
            declencher ( Evenements::onBtnM_RollUp );
        else
            declencher ( Evenements::onBtnM_RollDown );
    }   //  fin if survol
}







/////////////////////////////////////////////////
void
Bouton::traiter_evenements ( const sf::Event& event )
{
    // si actif et visible,
    if ( estActif() and estVisible() )  {

        // on s'occupe des declenchements
        gerer_declenchements ( event ) ;

        // et on s'occupe de l'�tat du bouton
        gerer_etat          ( event ) ;

        // on s'occupe des evenements clavier de la classe action
        Action::traiter_evenements( event );

    }
    // et on s'occupe de l'�tat du bouton
    gerer_etat          ( event ) ;

}




/////////////////////////////////////////////////
void
Bouton::actualiser ( float deltaT )
{
    // si il n'y a pas eu de changement sur le dessin du gadget on passe.
    if ( not m_aActualiser ) return;

    // on reinitialise le besoin d'actualiser.
    m_aActualiser = false;


    // on definie le style en fonction de l'�tat du bouton
    switch ( m_etat ) {

        case EtatBouton::desactive  : {
            m_style = m_skin->desactive;
            majGeom( );
        } break;

        case EtatBouton::repos      : {
            m_style = m_skin->btnRepos;
            majGeom( );
        } break;

        case EtatBouton::survol     : {
            m_style = m_skin->btnSurvol;
            majGeom( );
        } break;

        case EtatBouton::press      : {
            m_style = m_skin->btnPress;
            majGeom( );
        } break;

    }


}

/////////////////////////////////////////////////
void
Bouton::draw  ( sf::RenderTarget& target, sf::RenderStates states ) const    {

    if ( not m_visible ) return;


    states.transform *= getTransform();
    target.draw         ( *m_fond , states );
    // l'icone
    if ( m_bIcone )
        target.draw         ( *m_icone , states );

    for ( ptr enfant : m_enfants )
        target.draw      ( *enfant , states );
}

} // fin namespace gui
