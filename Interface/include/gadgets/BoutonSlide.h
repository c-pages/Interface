#ifndef BOUTONSLIDE_H
#define BOUTONSLIDE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>
#include <gadgets/Bouton.h>
#include <gadgets/Groupe.h>

namespace gui
{

/////////////////////////////////////////////////
/// \brief L'orientation du slide
///
/////////////////////////////////////////////////
enum Orientation{
    Verticale,      ///< Axe vertical
    Horizontale     ///< Axe horizontal
};



/////////////////////////////////////////////////
/// \brief Gadget, pour le defilement du contenu dans les fenetres
///
/// composé de 2 boutons :
///     -   le bouton glissière, se drag sur un axe.
///     -   le bouton du fond, celui herité. Il forme le fond et nous permet d'accéder directement à un endroit de la glissère
/// \todo cf. le todo du gui::Bouton
///
/////////////////////////////////////////////////
class BoutonSlide : public Gadget //, public UI
{
public:

   // class Bouton;

    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /// \param orient   l'orientation du bouton
    /// \param skin     le skin à utiliser
    /// \return
    ///
    /////////////////////////////////////////////////
    BoutonSlide (   sf::RenderWindow * m_fenetreSFML
                ,   Orientation             orient
                ,   std::shared_ptr<Skin>   skin        = new Skin()
                ,   float                   longueur    = 100       ) ;

    virtual ~BoutonSlide();



    /////////////////////////////////////////////////
    /// \brief Definir la taille
    ///
    /// \param taille
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille ) { m_btnFond->setSize( taille ); };

    /////////////////////////////////////////////////
    /// \brief Definir la taille
    ///
    /// \param taille
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize (  ) { return m_btnFond->getSize(  ); };

    /////////////////////////////////////////////////
    /// \brief  Definir la longueurMax
    ///
    /// \param  longeur
    ///
    /////////////////////////////////////////////////
    void
    setLongueurMax ( float longueur ){ m_longueurMax = longueur ; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief  Definir la longueurMax
    ///
    /// \param  longeur
    ///
    /////////////////////////////////////////////////
    float
    getLongueurMax ( )const { return m_longueurMax ; };


    /////////////////////////////////////////////////
    /// \brief Definir la longueur Courante
    ///
    /// \param longeur
    ///
    /////////////////////////////////////////////////
    void
    setLongueurCourante ( float longueur ){ m_longueurCourant = longueur ; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief Actualise le model du Gadget
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    majGeom();

    /////////////////////////////////////////////////
    /// \brief Acceder à la boundingBox local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getLocalBounds()const ;

    /////////////////////////////////////////////////
    /// \brief Acceder à la boundingBox global
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getGlobalBounds()const;


    /////////////////////////////////////////////////
    /// \brief Acceder à la boundingBox global
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSlidePos()const {return m_btnSlide->getPosition();};

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void
    creerUI();

    void
    initSkin ();


    /////////////////////////////////////////////////
    /// \brief Dessiner le bouton
    ///
    /////////////////////////////////////////////////
    bool
    isDragging() const { return m_drag; } ;



    /////////////////////////////////////////////////
    /// \brief La gestion des évènements utilisateurs.
    ///
    ///  Gère les entrées claviers, souris, fenetre ...
    ///
    /// \param event evenement SFML se transmettant depuis l'application
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    traiter_evenements ( const sf::Event& event );


    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// Actualiser les différents éléments du ou des écrans actifs.
    ///
    /// \param deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    actualiser ( float deltaT ) override;

    /////////////////////////////////////////////////
    /// \brief Dessiner le bouton
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;


private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    sf::RenderWindow *              m_fenetreSFML;      ///<  pointeur vers la fenetre SFML (pour la position absolue de la souris , pour les manips de la fenetre).
    float                           m_largeur;          ///<
    float                           m_longueurMax;      ///<
    float                           m_longueurCourant;  ///<
    std::shared_ptr<Bouton>         m_btnSlide;         ///<    Le Bouton glissant sur le fond
    std::shared_ptr<Bouton>         m_btnFond;          ///<    le bouton du fond premetant de glisser directment.
    Orientation                     m_orientation;      ///<    l'orientation de bouton

    std::shared_ptr<Skin>           m_skinBtnFond;

    // les drags
    bool            m_drag ;                            ///<  true quand on drag.
    sf::Vector2f    m_posBtnOrig;                       ///<  Position du bouton au debut du drag
    sf::Vector2f    m_posMouseOrig;                     ///<  Position de la souris au debut du drag

    FuncType        m_fctDrag_Debut;                    ///<  fonction pour le drag du contenu.
    FuncType        m_fctDrag_Fin;                      ///<  fonction pour le drag du contenu.

};
}; // fin namespace
#endif // BOUTONSLIDE_H
