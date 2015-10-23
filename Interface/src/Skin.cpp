
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>
#include <iostream>

namespace gui
{

/////////////////////////////////////////////////
Skin::Skin()
: fenetre       ( new Style () )
, btnRepos      ( new Style () )
, btnSurvol     ( new Style () )
, btnPress      ( new Style () )
, lblTitre      ( new Style () )
, lblCourant    ( new Style () )
{

    fenetre->txt_police.loadFromFile   ( "C:\\Windows\\Fonts\\arial.ttf" );
    fenetre->txt_style                  = sf::Text::Style::Regular ;
    fenetre->txt_taille                 = 12;
    fenetre->txt_couleur                = sf::Color ( 200,200,200);
    fenetre->lgn_epaisseur              = 1;
    fenetre->lgn_couleur                = sf::Color ( 255,255,255 , 20 );
    fenetre->fnd_couleur                = sf::Color ( 255,255,255 , 50 );
    //    fenetre->fnd_texture                = ;
    fenetre->align                      = Alignements::Libre ;
    fenetre->ajust                      = Ajustements::Sans ;

    // Style par defaut : Bouton repos
    btnRepos->txt_police.loadFromFile   ( "C:\\Windows\\Fonts\\arial.ttf" );
    btnRepos->txt_style                 = sf::Text::Style::Regular ;
    btnRepos->txt_taille                = 12;
    btnRepos->txt_couleur               = sf::Color ( 200,200,200);
    btnRepos->lgn_epaisseur             = 1;
    btnRepos->lgn_couleur               = sf::Color ( 255,255,255 , 50 );
    btnRepos->fnd_couleur               = sf::Color ( 255,255,255 , 100 );
    //    btnRepos->fnd_texture               = ;
    btnRepos->align                     = Alignements::Libre;
    btnRepos->ajust                     = Ajustements::Sans;

    // Style par defaut : Bouton survol
    btnSurvol->txt_police.loadFromFile  ( "C:\\Windows\\Fonts\\arial.ttf" );
    btnSurvol->txt_style                = sf::Text::Style::Regular;
    btnSurvol->txt_taille               = 12;
    btnSurvol->txt_couleur              = sf::Color ( 200,200,200);
    btnSurvol->lgn_epaisseur            = 1;
    btnSurvol->lgn_couleur              = sf::Color ( 255,255,255 , 150 );
    btnSurvol->fnd_couleur              = sf::Color ( 255,255,255 , 100 );
    //    btnSurvol->fnd_texture              = ;
    btnSurvol->align                    = Alignements::Libre;
    btnSurvol->ajust                    = Ajustements::Sans;

    // Style par defaut : Bouton press
    btnPress->txt_police.loadFromFile   ( "C:\\Windows\\Fonts\\arial.ttf" );
    btnPress->txt_style                 = sf::Text::Style::Regular;
    btnPress->txt_taille                = 12;
    btnPress->txt_couleur               = sf::Color ( 200,200,200);
    btnPress->lgn_epaisseur             = 1;
    btnPress->lgn_couleur               = sf::Color ( 255,255,255 , 200 );
    btnPress->fnd_couleur               = sf::Color ( 255,255,255 , 255 );
    //    btnPress->fnd_texture               = ;
    btnPress->align                     = Alignements::Libre;
    btnPress->ajust                     = Ajustements::Sans;

    // Style par defaut : Label Titre
    lblTitre->txt_police.loadFromFile   ( "C:\\Windows\\Fonts\\arial.ttf" );
    lblTitre->txt_style                 = sf::Text::Style::Regular ;
    lblTitre->txt_taille                = 15;
    lblTitre->txt_couleur               = sf::Color ( 200,200,200);
    lblTitre->lgn_epaisseur             = 1 ;
    lblTitre->lgn_couleur               = sf::Color ( 255,255,255 , 200 );
    lblTitre->fnd_couleur               = sf::Color ( 255,255,255 , 255 );
    //    lblTitre->fnd_texture               = ;
    lblTitre->align                     = Alignements::Libre;
    lblTitre->ajust                     = Ajustements::Sans;

    // Style par defaut : Label courant
    lblCourant->txt_police.loadFromFile ( "C:\\Windows\\Fonts\\arial.ttf" );
    lblCourant->txt_style               = sf::Text::Style::Regular;
    lblCourant->txt_taille              = 12;
    lblCourant->txt_couleur             = sf::Color ( 200,200,200);
    lblCourant->lgn_epaisseur           = 1;
    lblCourant->lgn_couleur             = sf::Color ( 255,255,255 , 200 );
    lblCourant->fnd_couleur             = sf::Color ( 255,255,255 , 255 );
    //    lblCourant->fnd_texture             = ;
    lblCourant->align                   = Alignements::Libre;
    lblCourant->ajust                   = Ajustements::Sans;

}

/////////////////////////////////////////////////
//Skin::~Skin()
//{
//    //dtor
//}

} // fin namespace gui
