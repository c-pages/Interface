
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
{
    m_btn->setSize ( taille );
    // integration dans le groupe UI
    m_grpUI->setParent ( this );
    m_grpUI->ajouter   ( m_btn );
    m_grpUI->ajouter   ( m_lbl );



m_curseur.setSize ( {1 , 20} );
m_curseur.setOutlineColor(sf::Color::White );
m_curseur.setOutlineThickness(1 );


    //ctor
    initUI();
}


/////////////////////////////////////////////////
ChampTexte::~ChampTexte()
{
    //dtor
}



/////////////////////////////////////////////////
void
ChampTexte::initUI()
{

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


    // gestion des entrées textes
    if ( m_btn->estCoche()
    and  event.type == sf::Event::TextEntered
    and  event.text.unicode < 128 ) {

        // le texte actuel
        std::string txt = m_lbl->getTexte() ;

        // retour arriere
        if ( event.text.unicode == 8 )  {
            txt.erase ( txt.size()-1 , 1);
            m_lbl->setTexte( txt  );

        }
        // entrée et echappe
        else if ( event.text.unicode == 13 or event.text.unicode == 27 )  {
            m_btn->setCoche( false);
        }
        else {
            std::cout << "ASCII character typed: " << event.text.unicode << std::endl;
            m_lbl->setTexte( txt + static_cast<char>(event.text.unicode)  );
        }
    }

}



/////////////////////////////////////////////////
void
ChampTexte::actualiser ( float deltaT )
{
    //m_curseur->setVi
    m_grpUI->actualiser ( deltaT );
    m_curseur.setPosition (      m_lbl->getSFTexte()->findCharacterPos 	( m_lbl->getTexte().size() )          );

//    if (m_btn->estCoche() )
//        m_curseur;
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
        target.draw ( m_curseur , states );


}



} // fin namespace


