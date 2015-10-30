#ifndef CONTENANT_H
#define CONTENANT_H









/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>
#include <UI.h>
#include <gadgets/Image.h>
#include <gadgets/BoutonSlide.h>

namespace gui {
class Groupe;
/////////////////////////////////////////////////
/// \brief Gadget  Un élément invisible permettant de rassembler des Gadgets.
///
/////////////////////////////////////////////////
class Contenant : public Gadget, public UI
{

public:
    Contenant( sf::RenderWindow  *     fenetre );
    virtual ~Contenant();

public:

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox des contenus
    ///
    /// \return la boundingBox des éléments enfants du groupe
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getContenuBounds ( ) const ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox locale
    ///
    /// \return la boundingBox locale .
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( ) const ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox globale
    ///
    /// \return la boundingBox globale des éléments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) const ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille à l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f
    getSize (  )const { return m_taille ; } ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille à l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
    ///
    /////////////////////////////////////////////////
    void
    setSize ( sf::Vector2f taille ) { m_taille = taille ; };



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
    sf::RenderWindow    *           m_fenetreSFML;
    bool                            m_bSliderVerti;     ///< true si on a besoin d'un slider vertical
    bool                            m_bSliderHori;      ///< true si on a besoin d'un slider horizontal
    sf::Vector2f                    m_taille;           ///<  Le taille de la fenetre.
    sf::Vector2f                    m_posContenu;       ///< la position du contenu ( quand on le slide )

    // les gadgets de la fenêtre
    std::shared_ptr<Groupe>         m_grpContenu;       ///<  Groupe des éléments du contenu de la Fenetre. ne s'affiche pas directment, est dessiné dans m_spriteContenant
    std::shared_ptr<Image>          m_fond;             ///<  Groupe des éléments du contenu de la Fenetre.
    std::shared_ptr<sf::Sprite>     m_spriteContenant;  ///<  Le sprite qui affiche le contenu de la fenetre.
    std::shared_ptr<BoutonSlide>    m_slideVerti;       ///< le bouton du slide vertical
    std::shared_ptr<BoutonSlide>    m_slideHori;        ///< le bouton du slide horizontal


};
};


////////////////////////////////////////////////////////////
/// \class gui::Contenant
/// \ingroup interface
///
/// Contient des éléments et gère un défilement quand contenant est plus grand que contenu
///
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////







#endif // CONTENANT_H
