
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>
#include <iostream>

namespace gui
{

/////////////////////////////////////////////////
Skin::Skin()
: desactive     ( Style () )
, fenetre       ( Style () )
, btnRepos      ( Style () )
, btnSurvol     ( Style () )
, btnPress      ( Style () )
, lblTitre      ( Style () )
, lblCourant    ( Style () )
{

    std::cout << "Skin par defaut\n";

    desactive.txt_police.loadFromFile   ( "media/polices/arial.ttf" );
    desactive.txt_style                  = sf::Text::Style::Regular ;
    desactive.txt_taille                 = 12;
    desactive.txt_couleur                = sf::Color ( 200,200,200);
    desactive.lgn_epaisseur              = 1;
    desactive.lgn_couleur                = sf::Color ( 255,255,255 , 20 );
    desactive.fnd_couleur                = sf::Color ( 255,255,255 , 50 );
    desactive.fnd_texture                = sf::Texture ();
    desactive.align                      = Alignements::Libre ;
    desactive.ajust                      = Ajustements::Sans ;

    fenetre.txt_police.loadFromFile   ( "media/polices/arial.ttf" );
    fenetre.txt_style                  = sf::Text::Style::Regular ;
    fenetre.txt_taille                 = 12;
    fenetre.txt_couleur                = sf::Color ( 200,200,200);
    fenetre.lgn_epaisseur              = 1;
    fenetre.lgn_couleur                = sf::Color ( 255,255,255 , 20 );
    fenetre.fnd_couleur                = sf::Color ( 255,255,255 , 50 );
    fenetre.fnd_texture                = sf::Texture ();
    fenetre.align                      = Alignements::Libre ;
    fenetre.ajust                      = Ajustements::Sans ;

    // Style par defaut : Bouton repos
    btnRepos.txt_police.loadFromFile   ( "media/polices/arial.ttf" );
    btnRepos.txt_style                 = sf::Text::Style::Regular ;
    btnRepos.txt_taille                = 12;
    btnRepos.txt_couleur               = sf::Color ( 200,200,200);
    btnRepos.lgn_epaisseur             = 1;
    btnRepos.lgn_couleur               = sf::Color ( 255,255,255 , 50 );
    btnRepos.fnd_couleur               = sf::Color ( 255,255,255 , 100 );
    btnRepos.fnd_texture               = sf::Texture ();
    btnRepos.align                     = Alignements::Libre;
    btnRepos.ajust                     = Ajustements::Sans;

    // Style par defaut : Bouton survol
    btnSurvol.txt_police.loadFromFile  ( "media/polices/arial.ttf" );
    btnSurvol.txt_style                = sf::Text::Style::Regular;
    btnSurvol.txt_taille               = 12;
    btnSurvol.txt_couleur              = sf::Color ( 200,200,200);
    btnSurvol.lgn_epaisseur            = 1;
    btnSurvol.lgn_couleur              = sf::Color ( 255,255,255 , 150 );
    btnSurvol.fnd_couleur              = sf::Color ( 255,255,255 , 100 );
    btnSurvol.fnd_texture              = sf::Texture ();
    btnSurvol.align                    = Alignements::Libre;
    btnSurvol.ajust                    = Ajustements::Sans;

    // Style par defaut : Bouton press
    btnPress.txt_police.loadFromFile   ( "media/polices/arial.ttf" );
    btnPress.txt_style                 = sf::Text::Style::Regular;
    btnPress.txt_taille                = 12;
    btnPress.txt_couleur               = sf::Color ( 200,200,200);
    btnPress.lgn_epaisseur             = 1;
    btnPress.lgn_couleur               = sf::Color ( 255,255,255 , 200 );
    btnPress.fnd_couleur               = sf::Color ( 255,255,255 , 150 );
    btnPress.fnd_texture               = sf::Texture ();
    btnPress.align                     = Alignements::Libre;
    btnPress.ajust                     = Ajustements::Sans;

    // Style par defaut : Label Titre
    lblTitre.txt_police.loadFromFile   ( "media/polices/arial.ttf" );
    lblTitre.txt_style                 = sf::Text::Style::Regular ;
    lblTitre.txt_taille                = 15;
    lblTitre.txt_couleur               = sf::Color ( 200,200,200);
    lblTitre.lgn_epaisseur             = 1 ;
    lblTitre.lgn_couleur               = sf::Color ( 255,255,255 , 200 );
    lblTitre.fnd_couleur               = sf::Color ( 255,255,255 , 255 );
    lblTitre.fnd_texture               = sf::Texture ();
    lblTitre.align                     = Alignements::Libre;
    lblTitre.ajust                     = Ajustements::Sans;

    // Style par defaut : Label courant
    lblCourant.txt_police.loadFromFile ( "media/polices/arial.ttf" );
    lblCourant.txt_style               = sf::Text::Style::Regular;
    lblCourant.txt_taille              = 12;
    lblCourant.txt_couleur             = sf::Color ( 200,200,200);
    lblCourant.lgn_epaisseur           = 1;
    lblCourant.lgn_couleur             = sf::Color ( 255,255,255 , 200 );
    lblCourant.fnd_couleur             = sf::Color ( 255,255,255 , 255 );
    lblCourant.fnd_texture             = sf::Texture ();
    lblCourant.align                   = Alignements::Libre;
    lblCourant.ajust                   = Ajustements::Sans;

}


/////////////////////////////////////////////////
Skin::Skin( const Skin& skin )
: desactive     ( skin.desactive )
, fenetre       ( skin.fenetre )
, btnRepos      ( skin.btnRepos )
, btnSurvol     ( skin.btnSurvol )
, btnPress      ( skin.btnPress )
, lblTitre      ( skin.lblTitre )
, lblCourant    ( skin.lblCourant )

{
    std::cout << "Skin par copy\n";
}










/////////////////////////////////////////////////
//Skin::~Skin()
//{
//    //dtor
//}

} // fin namespace gui
