#ifndef CONTENANT_H
#define CONTENANT_H


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>
#include <gadgets/Image.h>
#include <gadgets/BoutonSlide.h>
#include "gadgets/Groupe.h"

namespace gui {

/////////////////////////////////////////////////
/// \brief Gadget  Permet d'afficher un ensemble de gadget dans une fenetre de contenu.
///
/// Si le contenu est plus grand que le contenant, alors il y a des boutonSlider pour deplacer le contenu.
///
/////////////////////////////////////////////////
class Contenant : public Gadget  //, public UI
{

public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /// \param fenetre, la fenetre SFML dans laquelle on affiche ce cgadget
    ///
    /////////////////////////////////////////////////
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
    /// \brief Definir la taille
    ///
    /// \param taille la taille
    ///
    /////////////////////////////////////////////////
    void
    setSize ( sf::Vector2f taille ) { m_taille = taille ;};


    /////////////////////////////////////////////////
    /// \brief ajouter un enfant
    ///
    ///  on rajoute l'enfant dans le groups de contenu et non dans son m_enfants.
    ///
    /// \param enfant
    ///
    /////////////////////////////////////////////////
    virtual void
    ajouter( ptr enfant );

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


//////////// DEBUG /////////////////////////////////////
bool
contient ( float x, float y )
{
    sf::FloatRect rect  = getGlobalBounds();

//    ////////////DEBUG/////////////
//   // m_DEBUG_SHAPE.setPosition   ( rect.left  , rect.top      );
//    m_DEBUG_SHAPE.setSize       ( {rect.width , rect.height}   );
//    ////////////DEBUG/////////////

std::cout << "Contenant -> " << rect.left << " " << rect.top << " " << rect.width << " "<< rect.height << " ------> ";

    // S'il est contenu alors on verif le parent pour savoir par exemple si
    // le gadget est visible dans la fenetre parent.
    if ( rect.contains( sf::Vector2f ( x , y ) ) ){
            std::cout << "TRUE\n";
        if ( m_parent != 0 )    return  m_parent->contient ( x, y );
        else                    return  true;
    } else {
            std::cout << "FALSE\n";
        return false;
    }

};


////////// DEBUG /////////////////////////////////////

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    sf::RenderWindow    *           m_fenetreSFML;      ///< la fenetre SFML.
    bool                            m_bSliderVerti;     ///< true si on a besoin d'un slider vertical
    bool                            m_bSliderHori;      ///< true si on a besoin d'un slider horizontal
    sf::Vector2f                    m_taille;           ///< Le taille de la fenetre.
    sf::Vector2f                    m_posContenu;       ///< la position du contenu ( quand on le slide )

    // Contenant
    std::shared_ptr<Groupe>         m_grpContenant;     ///< groupe dans lequel se trouve le grp contenu, il sert principalement à limiter la zone de clique
    std::shared_ptr<Groupe>         m_grpContenu;       ///<  Groupe des éléments du contenu de la Fenetre. ne s'affiche pas directment, est dessiné dans m_spriteContenant
    std::shared_ptr<sf::Sprite>     m_spriteContenant;  ///<  Le sprite qui affiche le contenu de la fenetre.
    sf::Vector2i                    m_tailleTexture;
    sf::Vector2i                    m_tailleAffiche;

    // UI
    std::shared_ptr<Groupe>         m_grpUI;            ///<  les éléments d'interface du gadget
    std::shared_ptr<BoutonSlide>    m_slideVerti;       ///<  le bouton du slide vertical
    std::shared_ptr<BoutonSlide>    m_slideHori;        ///<  le bouton du slide horizontal


    ///////////////////////////DEBUG///////////////////////////////
    //std::shared_ptr<sf::RectangleShape>              m_debug;
    ///////////////////////////DEBUG///////////////////////////////
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
