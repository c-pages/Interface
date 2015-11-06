
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Utilitaires.h>
#include <../GUI.h>
#include "gadgets/BoutonFleche.h"
#include "gadgets/Bouton.h"
#include "gadgets/ChampTexte.h"



namespace gui
{

///////////////////////////////////////////////////
BoutonFleche::BoutonFleche()
: m_valeur      ( 0 )
, m_precision       ( 1 )
, m_champ       ( new ChampTexte() )
, m_btnPlus     ( new Bouton () )
, m_btnMoins    ( new Bouton () )
, m_taille      ( { 150 , 20 } )
{
    initUI  ( );
    majGeom ( );
}



///////////////////////////////////////////////////
BoutonFleche::~BoutonFleche()
{

}





/////////////////////////////////////////////////
void
BoutonFleche::initUI()
{
    // heritage
    m_champ->setParent      ( this );
    m_btnPlus->setParent    ( this );
    m_btnMoins->setParent   ( this );

    // icones
    m_btnPlus->setIcone     ( icoMngr.acceder( Icone::FlecheHaut ) );
    m_btnMoins->setIcone    ( icoMngr.acceder( Icone::FlecheBas ) );

    //
    m_champ->setType    ( ChampTexte::TypeEntree::chiffres );


    // fontions
    m_fctPlus = [this] () {
        setVal( m_valeur + m_precision );
    };
    m_fctMoins = [this] () {
        setVal( m_valeur - m_precision );
    };
    m_fctChange = [this] () {
        float val ( toFloat ( m_champ->getTexte() ) );
        m_valeur = val;
        setVal( val );
    };
    m_btnPlus->lier ( Evenements::onBtnG_Press , m_fctPlus );
    m_btnMoins->lier( Evenements::onBtnG_Press , m_fctMoins );
    m_champ->lier ( Evenements::onCha_ValideValeur , m_fctChange );


}


/////////////////////////////////////////////////
void
BoutonFleche::majGeom (  )
{
    sf::Vector2f    taille_btns = { 20 , 10 };

    m_champ->setSize        ( { m_taille.x - taille_btns.x , m_taille.y } );
    m_champ->setPosition    ( 0 , 0  );

    m_btnPlus->setSize      ( taille_btns );
    m_btnPlus->setPosition  ( m_taille.x - taille_btns.x , 0  );

    m_btnMoins->setSize     ( taille_btns );
    m_btnMoins->setPosition ( { m_taille.x - taille_btns.x    ,  m_taille.y - taille_btns.y } );

}


////////////////////////////////////////////////////
void
BoutonFleche::setSkin( std::shared_ptr<Skin>    skin )
{
    m_skin = skin;
    m_champ->setSkin ( skin );
    m_btnMoins->setSkin ( skin );
    m_btnPlus->setSkin ( skin );
}

/////////////////////////////////////////////////
void
BoutonFleche::setVal ( float val ) {
    m_valeur = val;
    m_champ->setTexte( toString( val) ) ;
};


/////////////////////////////////////////////////
sf::FloatRect
BoutonFleche::getLocalBounds ( ) const{

    sf::FloatRect result ( getPosition().x
                         , getPosition().y
                         , getSize().x
                         , getSize().y      );

    return  result ;
}


/////////////////////////////////////////////////
sf::FloatRect
BoutonFleche::getGlobalBounds ( ) const
{

    sf::FloatRect result ( getPosAbs().x
                         , getPosAbs().y
                         , getSize().x
                         , getSize().y      );

    return  result;
}


/////////////////////////////////////////////////
void
BoutonFleche::traiter_evenements ( const sf::Event& event )
{
    m_champ->traiter_evenements ( event );
    m_btnMoins->traiter_evenements ( event );
    m_btnPlus->traiter_evenements ( event );
}




/////////////////////////////////////////////////
void
BoutonFleche::actualiser ( float deltaT )
{

    m_champ->actualiser ( deltaT );
    m_btnMoins->actualiser ( deltaT );
    m_btnPlus->actualiser ( deltaT );
}


/////////////////////////////////////////////////
void
BoutonFleche::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
    if ( not m_visible ) return;


    states.transform *= getTransform();
    target.draw         ( *m_champ      , states );
    target.draw         ( *m_btnPlus    , states );
    target.draw         ( *m_btnMoins   , states );

 //   target.draw         ( *m_grpUI , states );
//    target.draw         ( *m_lbl , states );

//    for ( ptr enfant : m_enfants )
//        target.draw ( *enfant , states );
//
//    if (m_btn->estCoche() )
//        if ( m_clignot )
//            target.draw ( m_curseur , states );



}





} // fin namespace gui
