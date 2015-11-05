
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
, lblLog        ( std::make_shared <Style> () )
, cadre         ( std::make_shared <Style> () )
, invisible     ( std::make_shared <Style> () )
{

    /////////////////////////////////////////////////
    // Creation du Skin par defaut
    /////////////////////////////////////////////////

    //  la police par defaut du style
    sf::Font  police;
    if (!police.loadFromFile   ( "media/polices/arial.ttf" ) )    /// \todo faire un assert plutot, ou bien gerer la police par defaut avec un policeMngr
        std::cout << "Skin::Skin(): ERREUR CHARGEMENT POLICE DEFAUT 1\n";
    sf::Font  policeLog;

    if (!policeLog.loadFromFile   ( "media/polices/consola.ttf" ) )
        std::cout << "Skin::Skin(): ERREUR CHARGEMENT POLICE DEFAUT 2\n";



    float taillePolice = 20;

    //// DESACTIVE ///////////////////////////////////
    desactive->txt_police       = police;
    desactive->txt_style        = sf::Text::Style::Regular ;
    desactive->txt_taille       = taillePolice;
    desactive->txt_couleur      = sf::Color ( 255,255,255);
    desactive->lgn_epaisseur    = 1;
    desactive->lgn_couleur      = sf::Color ( 255,255,255 , 20 );
    desactive->fnd_couleur      = sf::Color ( 255,255,255 , 50 );
    desactive->fnd_texture      = sf::Texture ();
    desactive->align            = Alignements::Ctre_Mili ;
    desactive->ajust            = Ajustements::Sans ;

    //// FENETRE ///////////////////////////////////
    fenetre->txt_police         = police;
    fenetre->txt_style          = sf::Text::Style::Regular ;
    fenetre->txt_taille         = taillePolice;
    fenetre->txt_couleur        = sf::Color ( 255,255,255);
    fenetre->lgn_epaisseur      = 1;
    fenetre->lgn_couleur        = sf::Color ( 255,255,255 , 20 );
    fenetre->fnd_couleur        = sf::Color ( 255,255,255 , 50 );
    fenetre->fnd_texture        = sf::Texture ();
    fenetre->align              = Alignements::Ctre_Mili ;
    fenetre->ajust              = Ajustements::Sans ;

    //// BOUTON REPOS ///////////////////////////////////
    btnRepos->txt_police        = police;
    btnRepos->txt_style         = sf::Text::Style::Regular ;
    btnRepos->txt_taille        = taillePolice;
    btnRepos->txt_couleur       = sf::Color ( 100,255,100);
    btnRepos->lgn_epaisseur     = 0;
    btnRepos->lgn_couleur       = sf::Color ( 255,255,255 , 50 );
    btnRepos->fnd_couleur       = sf::Color ( 255,255,255 , 30 );
    btnRepos->fnd_texture       = sf::Texture ();
    btnRepos->align             = Alignements::Ctre_Mili;
    btnRepos->ajust             = Ajustements::Sans;

    //// BOUTON SURVOL ///////////////////////////////////
    btnSurvol->txt_police       = police;
    btnSurvol->txt_style        = sf::Text::Style::Regular;
    btnSurvol->txt_taille       = taillePolice;
    btnSurvol->txt_couleur      = sf::Color ( 255,255,255);
    btnSurvol->lgn_epaisseur    = 0;
    btnSurvol->lgn_couleur      = sf::Color ( 255,255,255 , 150 );
    btnSurvol->fnd_couleur      = sf::Color ( 255,255,255 , 75 );
    btnSurvol->fnd_texture      = sf::Texture ();
    btnSurvol->align            = Alignements::Ctre_Mili;
    btnSurvol->ajust            = Ajustements::Sans;

    //// BOUTON PRESS ///////////////////////////////////
    btnPress->txt_police        = police;
    btnPress->txt_style         = sf::Text::Style::Regular;
    btnPress->txt_taille        = taillePolice;
    btnPress->txt_couleur       = sf::Color ( 255,255,255);
    btnPress->lgn_epaisseur     = 0;
    btnPress->lgn_couleur       = sf::Color ( 255,255,255 , 200 );
    btnPress->fnd_couleur       = sf::Color ( 255,255,255 , 150 );
    btnPress->fnd_texture       = sf::Texture ();
    btnPress->align             = Alignements::Ctre_Mili;
    btnPress->ajust             = Ajustements::Sans;

    //// LABEL TITRE ///////////////////////////////////
    lblTitre->txt_police        = police;
    lblTitre->txt_style         = sf::Text::Style::Regular ;
    lblTitre->txt_taille        = taillePolice;
    lblTitre->txt_couleur       = sf::Color ( 200,200,200);
    lblTitre->lgn_epaisseur     = 1 ;
    lblTitre->lgn_couleur       = sf::Color ( 255,255,255 , 200 );
    lblTitre->fnd_couleur       = sf::Color ( 255,255,255 , 255 );
    lblTitre->fnd_texture       = sf::Texture ();
    lblTitre->align             = Alignements::Ctre_Mili;
    lblTitre->ajust             = Ajustements::Sans;

    //// LABEL COURANT ///////////////////////////////////
    lblCourant->txt_police      = police;
    lblCourant->txt_style       = sf::Text::Style::Regular;
    lblCourant->txt_taille      = taillePolice;
    lblCourant->txt_couleur     = sf::Color ( 200,200,200);
    lblCourant->lgn_epaisseur   = 1;
    lblCourant->lgn_couleur     = sf::Color ( 255,255,255 , 200 );
    lblCourant->fnd_couleur     = sf::Color ( 255,255,255 , 255 );
    lblCourant->fnd_texture     = sf::Texture ();
    lblCourant->align           = Alignements::Ctre_Mili;
    lblCourant->ajust           = Ajustements::Sans;

    //// LABEL LOG ///////////////////////////////////
    lblLog->txt_police      = policeLog;
    lblLog->txt_style       = sf::Text::Style::Regular;
    lblLog->txt_taille      = taillePolice;
    lblLog->txt_couleur     = sf::Color ( 200,200,200);
    lblLog->lgn_epaisseur   = 1;
    lblLog->lgn_couleur     = sf::Color ( 255,255,255 , 200 );
    lblLog->fnd_couleur     = sf::Color ( 255,255,255 , 255 );
    lblLog->fnd_texture     = sf::Texture ();
    lblLog->align           = Alignements::Ctre_Mili;
    lblLog->ajust           = Ajustements::Sans;

    //// cadre ///////////////////////////////////
    cadre->txt_police      = police;
    cadre->txt_style       = sf::Text::Style::Regular;
    cadre->txt_taille      = taillePolice;
    cadre->txt_couleur     = sf::Color ( 200,200,200);
    cadre->lgn_epaisseur   = 1;
    cadre->lgn_couleur     = sf::Color ( 255,255,255 , 100 );
    cadre->fnd_couleur     = sf::Color ( 255,255,255 , 0 );
    cadre->fnd_texture     = sf::Texture ();
    cadre->align           = Alignements::Ctre_Mili;
    cadre->ajust           = Ajustements::Sans;

    //// invisible ///////////////////////////////////
    lblCourant->txt_police      = police;
    lblCourant->txt_style       = sf::Text::Style::Regular;
    lblCourant->txt_taille      = taillePolice;
    lblCourant->txt_couleur     = sf::Color ( 200,200,200 , 200);
    lblCourant->lgn_epaisseur   = 0;
    lblCourant->lgn_couleur     = sf::Color ( 255,255,255 , 0 );
    lblCourant->fnd_couleur     = sf::Color ( 0,0,255 , 255 );
    lblCourant->fnd_texture     = sf::Texture ();
    lblCourant->align           = Alignements::Ctre_Mili;
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
