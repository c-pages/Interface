
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>
#include <iostream>

namespace gui
{

/////////////////////////////////////////////////
Skin::Skin()
: desactive     ( std::make_shared <Style> () )
, fenetre       ( std::make_shared <Style> () )
, btnRepos      ( std::make_shared <Style> () )
, btnSurvol     ( std::make_shared <Style> () )
, btnPress      ( std::make_shared <Style> () )
, lblTitre      ( std::make_shared <Style> () )
, lblCourant    ( std::make_shared <Style> () )
, cadre         ( std::make_shared <Style> () )
, invisible     ( std::make_shared <Style> () )
{
    std::cout << "INIT SKIN\n";
    /////////////////////////////////////////////////
    // Creation du Skin par defaut
    /////////////////////////////////////////////////

    //  la police par defaut du style
    sf::Font  police;
    police.loadFromFile   ( "media/polices/arial.ttf" );

    //// DESACTIVE ///////////////////////////////////
    desactive->txt_police       = police;
    desactive->txt_style        = sf::Text::Style::Regular ;
    desactive->txt_taille       = 2;
    desactive->txt_couleur      = sf::Color ( 200,200,200);
    desactive->lgn_epaisseur    = 1;
    desactive->lgn_couleur      = sf::Color ( 255,255,255 , 20 );
    desactive->fnd_couleur      = sf::Color ( 255,255,255 , 50 );
    desactive->fnd_texture      = sf::Texture ();
    desactive->align            = Alignements::Libre ;
    desactive->ajust            = Ajustements::Sans ;

    //// FENETRE ///////////////////////////////////
    fenetre->txt_police         = police;
    fenetre->txt_style          = sf::Text::Style::Regular ;
    fenetre->txt_taille         = 2;
    fenetre->txt_couleur        = sf::Color ( 200,200,200);
    fenetre->lgn_epaisseur      = 1;
    fenetre->lgn_couleur        = sf::Color ( 255,255,255 , 20 );
    fenetre->fnd_couleur        = sf::Color ( 255,255,255 , 50 );
    fenetre->fnd_texture        = sf::Texture ();
    fenetre->align              = Alignements::Libre ;
    fenetre->ajust              = Ajustements::Sans ;

    //// BOUTON REPOS ///////////////////////////////////
    btnRepos->txt_police        = police;
    btnRepos->txt_style         = sf::Text::Style::Regular ;
    btnRepos->txt_taille        = 2;
    btnRepos->txt_couleur       = sf::Color ( 200,200,200);
    btnRepos->lgn_epaisseur     = 1;
    btnRepos->lgn_couleur       = sf::Color ( 255,255,255 , 50 );
    btnRepos->fnd_couleur       = sf::Color ( 255,255,255 , 100 );
    btnRepos->fnd_texture       = sf::Texture ();
    btnRepos->align             = Alignements::Libre;
    btnRepos->ajust             = Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    btnSurvol->txt_police       = police;
    btnSurvol->txt_style        = sf::Text::Style::Regular;
    btnSurvol->txt_taille       = 2;
    btnSurvol->txt_couleur      = sf::Color ( 200,200,200);
    btnSurvol->lgn_epaisseur    = 1;
    btnSurvol->lgn_couleur      = sf::Color ( 255,255,255 , 150 );
    btnSurvol->fnd_couleur      = sf::Color ( 255,255,255 , 100 );
    btnSurvol->fnd_texture      = sf::Texture ();
    btnSurvol->align            = Alignements::Libre;
    btnSurvol->ajust            = Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    btnPress->txt_police        = police;
    btnPress->txt_style         = sf::Text::Style::Regular;
    btnPress->txt_taille        = 2;
    btnPress->txt_couleur       = sf::Color ( 200,200,200);
    btnPress->lgn_epaisseur     = 1;
    btnPress->lgn_couleur       = sf::Color ( 255,255,255 , 200 );
    btnPress->fnd_couleur       = sf::Color ( 255,255,255 , 150 );
    btnPress->fnd_texture       = sf::Texture ();
    btnPress->align             = Alignements::Libre;
    btnPress->ajust             = Ajustements::Sans;

    //// LABEL TITRE ///////////////////////////////////
    lblTitre->txt_police        = police;
    lblTitre->txt_style         = sf::Text::Style::Regular ;
    lblTitre->txt_taille        = 2;
    lblTitre->txt_couleur       = sf::Color ( 200,200,200);
    lblTitre->lgn_epaisseur     = 1 ;
    lblTitre->lgn_couleur       = sf::Color ( 255,255,255 , 200 );
    lblTitre->fnd_couleur       = sf::Color ( 255,255,255 , 255 );
    lblTitre->fnd_texture       = sf::Texture ();
    lblTitre->align             = Alignements::Libre;
    lblTitre->ajust             = Ajustements::Sans;

    //// LABEL COURANT ///////////////////////////////////
    lblCourant->txt_police      = police;
    lblCourant->txt_style       = sf::Text::Style::Regular;
    lblCourant->txt_taille      = 2;
    lblCourant->txt_couleur     = sf::Color ( 200,200,200);
    lblCourant->lgn_epaisseur   = 1;
    lblCourant->lgn_couleur     = sf::Color ( 255,255,255 , 200 );
    lblCourant->fnd_couleur     = sf::Color ( 255,255,255 , 255 );
    lblCourant->fnd_texture     = sf::Texture ();
    lblCourant->align           = Alignements::Libre;
    lblCourant->ajust           = Ajustements::Sans;

    //// cadre ///////////////////////////////////
    cadre->txt_police      = police;
    cadre->txt_style       = sf::Text::Style::Regular;
    cadre->txt_taille      = 2;
    cadre->txt_couleur     = sf::Color ( 200,200,200);
    cadre->lgn_epaisseur   = 1;
    cadre->lgn_couleur     = sf::Color ( 255,255,255 , 100 );
    cadre->fnd_couleur     = sf::Color ( 255,255,255 , 0 );
    cadre->fnd_texture     = sf::Texture ();
    cadre->align           = Alignements::Libre;
    cadre->ajust           = Ajustements::Sans;

    //// invisible ///////////////////////////////////
    lblCourant->txt_police      = police;
    lblCourant->txt_style       = sf::Text::Style::Regular;
    lblCourant->txt_taille      = 0;
    lblCourant->txt_couleur     = sf::Color ( 200,200,200 , 0);
    lblCourant->lgn_epaisseur   = 0;
    lblCourant->lgn_couleur     = sf::Color ( 255,255,255 , 0 );
    lblCourant->fnd_couleur     = sf::Color ( 0,0,255 , 255 );
    lblCourant->fnd_texture     = sf::Texture ();
    lblCourant->align           = Alignements::Libre;
    lblCourant->ajust           = Ajustements::Sans;

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
