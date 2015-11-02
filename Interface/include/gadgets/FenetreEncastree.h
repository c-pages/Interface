#ifndef FENETREENCASTREE_H
#define FENETREENCASTREE_H

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
/// \brief les types d'ajustements des éléments entre eux.
///
/// Ajuster la taille d'un gadget par rapport à la taille d'un autre.
/// Le bouton par rapport au texte d'un BoutonTexte par exemple.
///
/// \todo à developper.
///
/////////////////////////////////////////////////
enum Encastrements {
        Gauche      ///<
    ,   Droite      ///<
    ,   Haut        ///<
    ,   Bas         ///<
};

/////////////////////////////////////////////////
/// \brief une fenetre encastrée dans un des quatre coté de la fenêtre SFML.
///
/// Avec une possibilité de redimensionner la fenetre sur le coté libre.
///
/////////////////////////////////////////////////
class FenetreEncastree: public Gadget
{

public:
    FenetreEncastree   ( sf::RenderWindow  *       fenetre
                        , std::shared_ptr<Skin>     skin            = new Skin()
                        , Encastrements             encastrement    = Encastrements::Gauche );


    virtual ~FenetreEncastree();


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
    bool    m_redimensionnable;           ///<  option: La fenetre est redimensionnable (true) ou pas (false).
    bool    m_fermable;                   ///<  option: La fenetre est fermable (true) ou pas (false).

    /////////// les Boutons de l'ui  ///////////

    std::shared_ptr<Groupe>         m_grpUI;                ///<  Le groupe contenant l'interface de la fenetyre (boutons, titre)
    std::shared_ptr<Label>          m_lblTitre;             ///<  Le Label titre.

    std::shared_ptr<BoutonTexte>    m_btnFermer;            ///<  Le Bouton pour fermer la fenetre.

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
    bool            m_redimDroite;        ///<  En train de redim ?.
    bool            m_redimGauche;        ///<  En train de redim ?.
    bool            m_redimBas;           ///<  En train de redim ?.
    bool            m_redimHaut;          ///<  En train de redim ?.
    sf::Vector2f    m_posFenetreOrig;     ///<  position de la fenetre à l'origine du drag.
    sf::Vector2f    m_posMouseOrig;       ///<  position de la souris a l'origine du drag.
    sf::Vector2f    m_tailleFenetreOrig;  ///<  taille de la fenetre à l'origine.

    /////////// les fonctions de manipulation de la fenetre ///////////


    // les fonctions fermer
    FuncType    m_fctFermer;              ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctFermerEntre;         ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctFermerSort;          ///<  fonction pour manipuler la fenetre.

    // les fonctions redimension arretes
    FuncType    m_fctRedimDroiteDebut;    ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimDroiteFin;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimGaucheDebut;    ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimGaucheFin;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasDebut;       ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimBasFin;         ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautDebut;      ///<  fonction pour manipuler la fenetre.
    FuncType    m_fctRedimHautFin;        ///<  fonction pour manipuler la fenetre.




};
}; // fin namespace
#endif // FENETREENCASTREE_H

////////////////////////////////////////////////////////////
/// \class gui::FenetreEncastree
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////
