#include "Config.h"


#include <iostream>


namespace app
{


/////////////////////////////////////////////////
//initialisation des membres statics
/////////////////////////////////////////////////
ResourceMgr<sf::Font,int>                   Config::m_polices;
sf::Time                                    Config::m_dureeImage  ;
std::map < Config::Skins  , gui::Skin * >   Config::m_skins = {};
std::map < Config::Styles , gui::Style * >  Config::m_styles = {};





/////////////////////////////////////////////////
Config::Config()
{
    //ctor
}



/////////////////////////////////////////////////
Config::~Config()
{
    //dtor
}


/////////////////////////////////////////////////
sf::Time
Config::getDureeImage()
{
    return m_dureeImage;
}


/////////////////////////////////////////////////
void Config::init()
{
    m_dureeImage =     sf::seconds (1.f / 60.f);

    initPolices();
    initTextures();
    initSkins();
    initStyles();
}


/////////////////////////////////////////////////
void Config::initPolices()
{
    Config::m_polices.load( Polices::police_1 , "media/polices/arial.ttf"  );
    Config::m_polices.load( Polices::police_2 , "media/polices/bgothl.ttf"  );
}


/////////////////////////////////////////////////
void Config::initTextures()
{
  //  _textures.

}
/////////////////////////////////////////////////
void Config::initSkins()
{

    /////////////////////////////////////////////////
    // Skin1
    /////////////////////////////////////////////////
    // Enregistrement du skin dans la pile de skin.
    m_skins.insert ( { Config::Skins::Skin1 , new gui::Skin() } ) ;
    gui::Skin* skin1 = m_skins[ Config::Skins::Skin1 ];

    //  la police du style
    sf::Font  police;
    police = m_polices.get( Polices::police_2 );

    // Style par defaut des Bouton repos
    skin1->fenetre->txt_police      = police;
    skin1->fenetre->txt_style       = sf::Text::Style::Regular ;
    skin1->fenetre->txt_taille      = 12;
    skin1->fenetre->txt_couleur     = sf::Color ( 200,200,200);
    skin1->fenetre->lgn_epaisseur   = 1;
    skin1->fenetre->lgn_couleur     = sf::Color ( 255,255,255 , 20 );
    skin1->fenetre->fnd_couleur     = sf::Color ( 255,255,255 , 50 );
    //skin1->fenetre->fnd_texture                = ;
    skin1->fenetre->align           = gui::Alignements::Libre ;
    skin1->fenetre->ajust           = gui::Ajustements::Sans ;

    // Style par defaut des Bouton repos
    skin1->btnRepos->txt_police     = police;
    skin1->btnRepos->txt_style      = sf::Text::Style::Regular ;
    skin1->btnRepos->txt_taille     = 12;
    skin1->btnRepos->txt_couleur    = sf::Color ( 200,200,200);
    skin1->btnRepos->lgn_epaisseur  = 1;
    skin1->btnRepos->lgn_couleur    = sf::Color ( 255,255,255 , 50 );
    skin1->btnRepos->fnd_couleur    = sf::Color ( 255,255,255 , 100 );
    //skin1->btnRepos->fnd_texture               = ;
    skin1->btnRepos->align          = gui::Alignements::Libre;
    skin1->btnRepos->ajust          = gui::Ajustements::Sans;

    // Style par defaut des Bouton survol
    skin1->btnSurvol->txt_police    = police;
    skin1->btnSurvol->txt_style     = sf::Text::Style::Regular;
    skin1->btnSurvol->txt_taille    = 12;
    skin1->btnSurvol->txt_couleur   = sf::Color ( 200,200,200);
    skin1->btnSurvol->lgn_epaisseur = 1;
    skin1->btnSurvol->lgn_couleur   = sf::Color ( 255,255,255 , 150 );
    skin1->btnSurvol->fnd_couleur   = sf::Color ( 255,255,255 , 100 );
    //skin1->btnSurvol->fnd_texture              = ;
    skin1->btnSurvol->align         = gui::Alignements::Libre;
    skin1->btnSurvol->ajust         = gui::Ajustements::Sans;

    // Style par defaut des Bouton press
    skin1->btnPress->txt_police     = police;
    skin1->btnPress->txt_style      = sf::Text::Style::Regular;
    skin1->btnPress->txt_taille     = 12;
    skin1->btnPress->txt_couleur    = sf::Color ( 200,200,200);
    skin1->btnPress->lgn_epaisseur  = 1;
    skin1->btnPress->lgn_couleur    = sf::Color ( 255,255,255 , 200 );
    skin1->btnPress->fnd_couleur    = sf::Color ( 255,255,255 , 255 );
    //skin1->btnPress->fnd_texture               = ;
    skin1->btnPress->align          = gui::Alignements::Libre;
    skin1->btnPress->ajust          = gui::Ajustements::Sans;

    // Style par defaut des Label Titre
    skin1->lblTitre->txt_police     = police;
    skin1->lblTitre->txt_style      = sf::Text::Style::Regular ;
    skin1->lblTitre->txt_taille     = 15;
    skin1->lblTitre->txt_couleur    = sf::Color ( 200,200,200);
    skin1->lblTitre->lgn_epaisseur  = 1 ;
    skin1->lblTitre->lgn_couleur    = sf::Color ( 255,255,255 , 200 );
    skin1->lblTitre->fnd_couleur    = sf::Color ( 255,255,255 , 255 );
    //skin1->lblTitre->fnd_texture               = ;
    skin1->lblTitre->align          = gui::Alignements::Libre;
    skin1->lblTitre->ajust          = gui::Ajustements::Sans;

    // Style par defaut des Label courant
    skin1->lblCourant->txt_police   = police;
    skin1->lblCourant->txt_style    = sf::Text::Style::Regular;
    skin1->lblCourant->txt_taille   = 12;
    skin1->lblCourant->txt_couleur  = sf::Color ( 200,200,200);
    skin1->lblCourant->lgn_epaisseur= 1;
    skin1->lblCourant->lgn_couleur  = sf::Color ( 255,255,255 , 200 );
    skin1->lblCourant->fnd_couleur  = sf::Color ( 255,255,255 , 255 );
    //skin1->lblCourant->fnd_texture             = ;
    skin1->lblCourant->align        = gui::Alignements::Libre;
    skin1->lblCourant->ajust        = gui::Ajustements::Sans;

}

/////////////////////////////////////////////////
void Config::initStyles()
{

//    _styles.insert ( { gui::Styles::Root , new gui::Style() } ) ;
//
//    _styles[ gui::Styles::Root ]->txtPolice     =   _polices.get( m_polices::police_2 );
//    _styles[ gui::Styles::Root ]->txtTaille     =   15;
//    _styles[ gui::Styles::Root ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Root ]->lgnEpaisseur  =   0;
//    _styles[ gui::Styles::Root ]->lgnCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Root ]->fndCouleur    =   sf::Color ( 20 , 20 , 20 );
//    _styles[ gui::Styles::Root ]->alignement    =   gui::Align::Sans;
//
//
//    _styles.insert ( { gui::Styles::Fenetre_1 , new gui::Style() } ) ;
//
//    _styles[ gui::Styles::Fenetre_1 ]->txtPolice     =   _polices.get( m_polices::police_2 );
//    _styles[ gui::Styles::Fenetre_1 ]->txtTaille     =   15;
//    _styles[ gui::Styles::Fenetre_1 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Fenetre_1 ]->lgnEpaisseur  =   1;
//    _styles[ gui::Styles::Fenetre_1 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
//    _styles[ gui::Styles::Fenetre_1 ]->fndCouleur    =   sf::Color ( 25 , 25 , 25 );
//    _styles[ gui::Styles::Fenetre_1 ]->alignement    =   gui::Align::Hori;
//
//
//    _styles.insert ( { gui::Styles::Menu_1 , new gui::Style() } ) ;
//
//    _styles[ gui::Styles::Menu_1 ]->txtPolice     =   _polices.get( m_polices::police_2 );
//    _styles[ gui::Styles::Menu_1 ]->txtTaille     =   15;
//    _styles[ gui::Styles::Menu_1 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Menu_1 ]->lgnEpaisseur  =   1;
//    _styles[ gui::Styles::Menu_1 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
//    _styles[ gui::Styles::Menu_1 ]->fndCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Menu_1 ]->alignement    =   gui::Align::Hori;
//
//
//    _styles.insert ( { gui::Styles::Menu_2 , new gui::Style() } ) ;
//
//    _styles[ gui::Styles::Menu_2 ]->txtPolice     =   _polices.get( m_polices::police_1 );
//    _styles[ gui::Styles::Menu_2 ]->txtTaille     =   10;
//    _styles[ gui::Styles::Menu_2 ]->txtCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Menu_2 ]->lgnEpaisseur  =   1;
//    _styles[ gui::Styles::Menu_2 ]->lgnCouleur    =   sf::Color ( 255 , 255 , 255, 50 );
//    _styles[ gui::Styles::Menu_2 ]->fndCouleur    =   sf::Color ( 200 , 200 , 200 );
//    _styles[ gui::Styles::Menu_2 ]->alignement    =   gui::Align::Hori;

}


}




















