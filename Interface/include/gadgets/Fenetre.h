#ifndef FENETRE_H
#define FENETRE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {

class Groupe;
class Label;
class Bouton;
class BoutonTexte;
class Image;
class Contenant;

/////////////////////////////////////////////////
/// \brief Gadget  permettant de rassembler des Gadgets au sein d'une Fenetre.
///
/////////////////////////////////////////////////
class Fenetre : public Gadget
{

public:

    /////////////////////////////////////////////////
    /// \brief Constructeur avec Skin
    ///
    /// \param fenetre la fenêtre SFML
    /// \param skin     Le skin a appliquer à la fenêtre
    ///
    /////////////////////////////////////////////////
    Fenetre(    sf::RenderWindow  * fenetre
            ,   std::shared_ptr<Skin>  skin  );


    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /// \param fenetre la fenêtre de rendu SFML.
    /// \param taille du gadget.
    /// \param depl option: fenêtre draggale.
    /// \param ferm option: fenêtre avec bouton pour la fermer.
    /// \param redim option: fenêtre redimensionnable
    ///.
    /////////////////////////////////////////////////
    Fenetre(    sf::RenderWindow  * fenetre
            ,   sf::Vector2f        taille  = { 100 , 100 }
            ,   bool                depl    = true
            ,   bool                ferm    = true
            ,   bool                redim   = true );

    virtual ~Fenetre();


    /////////////////////////////////////////////////
    /// \brief Definir la taille du contenu
    ///
    /// \param taille, c'est la taille du cadre du contenu, sans les boutons de la fenetres.
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille ) {
        m_taille = taille ;
        majGeom ();
    };

    /////////////////////////////////////////////////
    /// \brief Acceder à la taille de la fenetre
    ///
    /// \return la taille reel de la fenetre avec boutons..
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( )  const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) const ;

    /////////////////////////////////////////////////
    /// \brief ajouter un enfant
    ///
    ///  Pour une fenetre on rajoute l'enfant dans le groups de contenu.
    ///
    /// \param enfant
    ///
    /////////////////////////////////////////////////
    virtual void
    ajouter( ptr enfant );

    /////////////////////////////////////////////////
    /// \brief Definir le titre.
    ///
    /// \param titre le nouveau titre.
    ///
    /////////////////////////////////////////////////
    void
    setTitre ( std::string titre);

    /////////////////////////////////////////////////
    /// \brief Definir le skin.
    ///
    /// \param titre le nouveau skin.
    ///
    /////////////////////////////////////////////////
    void
    setSkin ( std::shared_ptr<Skin>    skin ) ;


    /////////////////////////////////////////////////
    /// \brief appeler le titre.
    ///
    /// \return le titre.
    ///
    /////////////////////////////////////////////////
    std::string
    getTitre (  );

    /////////////////////////////////////////////////
    /// \brief Definir l'epaisseur de la bordure
    ///
    /// la bordure contient les boutons de recadrage
    ///
    /// \param bordure
    ///
    /////////////////////////////////////////////////
    void
    setBordure ( float bordure ) { m_bordure = bordure; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief renvois la bordure
    ///
    /// \return la bordure
    ///
    /////////////////////////////////////////////////
    float
    getBordure (  ) { return m_bordure ; };

private:



    /////////////////////////////////////////////////
    /// \brief Initialiser le Skin des bouton de l'interface.
    ///
    /////////////////////////////////////////////////
    void
    initSkinBouton();

    /////////////////////////////////////////////////
    /// \brief Initialiser les gadgets ( boutons, titre...).
    ///
    /////////////////////////////////////////////////
    void
    initUI();

    /////////////////////////////////////////////////
    /// \brief Initialiser l'interface pour prendre en compte le drag.
    ///
    /////////////////////////////////////////////////
    void
    initUI_drag();

    /////////////////////////////////////////////////
    /// \brief Initialiser l'interface pour le bouton fermer.
    ///
    /////////////////////////////////////////////////
    void
    initUI_fermer();

    /////////////////////////////////////////////////
    /// \brief Initialiser l'interface pour les bouton de redimensionnements.
    ///
    /////////////////////////////////////////////////
    void
    initUI_redim();

    /////////////////////////////////////////////////
    /// \brief Initialiser l'interface pour le titre.
    ///
    /////////////////////////////////////////////////
    void
    initUI_titre();

    /////////////////////////////////////////////////
    /// \brief mais à jour les styles des éléments de la fenêtre.
    ///
    /////////////////////////////////////////////////
    virtual void
    updateStyle( );

    /////////////////////////////////////////////////
    /// \brief Mettre à jour les gémotries de la fenêtre
    ///
    /////////////////////////////////////////////////
    void
    majGeom (  )  ;

    /////////////////////////////////////////////////
    /// \brief les manipulation de drag et de redimensionnement.
    ///
    /////////////////////////////////////////////////
    void
    ManipulerFenetre ( );

public:

    /////////////////////////////////////////////////
    /// \brief La gestion des évènements utilisateurs.
    ///
    ///  Gère les entrées claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// Actualiser les différents éléments du ou des écrans actifs.
    /// \param deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ( float deltaT ) ;

    /////////////////////////////////////////////////
    /// \brief Rendre les éléments.
    ///
    /// Dessiner les différents éléments du ou des écrans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::RenderWindow *      m_fenetreSFML;  ///<  pointeur vers la fenetre SFML (pour la position absolue de la souris , pour les manips de la fenetre).
    float                   m_bordure;      ///<  Le taille de la bordure du cadre.
    sf::Vector2f            m_taille;       ///<  Le taille de la fenetre.
    std::shared_ptr<Skin>   m_skinBtn;      ///<  Le skin pour les boutons de la fenetre (drag, fermer, redim. ...)

    /////////// les options de la fenetre ///////////
    bool    m_deplacable;                 ///<  option: La fenetre est deplaçable (true) ou pas (false).
    bool    m_redimensionnable;           ///<  option: La fenetre est redimensionnable (true) ou pas (false).
    bool    m_fermable;                   ///<  option: La fenetre est fermable (true) ou pas (false).


    /////////// les Boutons de l'ui  ///////////

    std::shared_ptr<Groupe>         m_grpUI;                ///<  Le groupe contenant l'interface de la fenetyre (boutons, titre)
    std::shared_ptr<Label>          m_lblTitre;             ///<  Le Label titre.
 //   std::shared_ptr<Label>          m_lblFermer;            ///<  Le X pour le bouton fermer.

    std::shared_ptr<BoutonTexte>         m_btnFermer;            ///<  Le Bouton pour fermer la fenetre.
    std::shared_ptr<Bouton>         m_btnDrag;              ///<  Le Bouton pour drager la fenetre.

    std::shared_ptr<Bouton>         m_btnRedimBasDroite;    ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimBasGauche;    ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimHautDroite;   ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimHautGauche;   ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimGauche;       ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimDroite;       ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimBas;          ///<  Bouton pour redimensionner la fenetre.
    std::shared_ptr<Bouton>         m_btnRedimHaut;         ///<  Bouton pour redimensionner la fenetre.

    /////////// le contenant de la fenetre  ///////////
    std::shared_ptr<Image>          m_CadreContenu;         ///<  Dessine un cadre autour du contenant
    std::shared_ptr<Contenant>      m_contenant;            ///<  Le contenant qui affiche le contenu de la fenetre.

    /////////// le fond  ///////////
    std::shared_ptr<Image>          m_fond;                 ///<  Le rectangle du fond.



    /////////// Pour drager et redimensionner la fenetre ///////////
    bool            m_dragging;           ///<  En train de dragger ?
    bool            m_redimDroite;        ///<  En train de redim ?.
    bool            m_redimGauche;        ///<  En train de redim ?.
    bool            m_redimBas;           ///<  En train de redim ?.
    bool            m_redimHaut;          ///<  En train de redim ?.
    sf::Vector2f    m_posFenetreOrig;     ///<  position de la fenetre à l'origine du drag.
    sf::Vector2f    m_posMouseOrig;       ///<  position de la souris a l'origine du drag.
    sf::Vector2f    m_tailleFenetreOrig;  ///<  taille de la fenetre à l'origine.

    /////////// les fonctions de manipulation de la fenetre ///////////

    // les fonctions pour le drag
    FuncType    m_fctDragDebut;           ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctDragFin;             ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctDragEntre;           ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctDragSort;            ///<  fonction pour manipuler la fenetre.

    // les fonctions fermer
    FuncType    m_fctFermer;              ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctFermerEntre;         ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctFermerSort;          ///<  fonction pour manipuler la fenetre.

    // les fonctions redimension coins
    FuncType    m_fctRedimBasDroiteDebut; ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasDroiteFin;   ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasGaucheDebut; ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasGaucheFin;   ///<  fonction pour manipuler la fenetre.

    FuncType    m_fctRedimHautDroiteDebut; ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautDroiteFin;   ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautGaucheDebut; ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautGaucheFin;   ///<  fonction pour manipuler la fenetre.

    // les fonctions redimension arretes
    FuncType    m_fctRedimDroiteDebut;    ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimDroiteFin;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimGaucheDebut;    ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimGaucheFin;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasDebut;       ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasFin;         ///<  fonction pour manipuler la fenetre.

    FuncType    m_fctRedimHautDebut;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautFin;        ///<  fonction pour manipuler la fenetre.

std::shared_ptr<sf::RectangleShape>  m_debug;



//
////////////// DEBUG /////////////////////////////////////
//bool
//contient ( float x, float y )
//{
//    sf::FloatRect rect  = getGlobalBounds();
//
////    ////////////DEBUG/////////////
////   // m_DEBUG_SHAPE.setPosition   ( rect.left  , rect.top      );
////    m_DEBUG_SHAPE.setSize       ( {rect.width , rect.height}   );
////    ////////////DEBUG/////////////
//
//std::cout << "Fenetre -> " << rect.left << " " << rect.top << " " << rect.width << " "<< rect.height << " ------> ";
//
//    // S'il est contenu alors on verif le parent pour savoir par exemple si
//    // le gadget est visible dans la fenetre parent.
//    if ( rect.contains( sf::Vector2f ( x , y ) ) ){
//            std::cout << "TRUE\n";
//        if ( m_parent != 0 )    return  m_parent->contient ( x, y );
//        else                    return  true;
//    } else {
//            std::cout << "FALSE\n";
//        return false;
//    }
//
//};
////////////// DEBUG /////////////////////////////////////


};

};

#endif // FENETRE_H


////////////////////////////////////////////////////////////
/// \class gui::Fenetre
/// \ingroup interface
///
/// Les differents axes d'une fenêtre:
/// \code
///
/// \todo faire le bouton fermer avec un gui::BoutonTexte
///
///    // ////////////////////////////////////////////////////////////////////////////////////
///    //                                                                                   //
///    //                HORIZ_...                                                          //
///    //                                                                                   //
///    //  VERTI_...     0    1                 3     2    Total                            //
///    //                |    |                 |     |    |                                //
///    //      0 ---     |----|-----------------------|----|  ---                           //
///    //                |Red.|      Redimension      |Red.|      m_bordure                 //
///    //      1 ---     |----|-----------------|-----|----|  ---                           //
///    //                |    |                 |     |    |      m_lblTitre->getSize().y   //
///    //                |    |  Titre/drag     |Ferm.|    |  ---                           //
///    //                |    |                 |     |    |      m_bordure                 //
///    //      2 ---     |   0.0----------------|-----|    |  ---                           //
///    //                |Red.|                       |Red.|                                //
///    //                |    |                       |    |                                //
///    //                |    |      Contenu          |    |      taille.y                  //
///    //                |    |      ( taille )       |    |                                //
///    //                |    |                       |    |                                //
///    //      3 ---     |----|-----------------------|----|  ---                           //
///    //                |Red.|      Redimemsion      |Red.|      m_bordure                 //
///    //  Total ---     |----|-----------------------|----|  ---                           //
///    //                                                                                   //
///    //                |    |                       |    |                                //
///    //               m_bordure      taille.x      m_bordure                              //
///    //                                                                                   //
///    ///////////////////////////////////////////////////////////////////////////////////////
///
///
/// \endcode
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////




