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
    /// \brief Constructeur par d�faut
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
    /// \return la boundingBox des �l�ments enfants du groupe
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
    /// \return la boundingBox globale des �l�ments enfants du groupe.
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( ) const ;


    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return la taille � l'aide la sa bounding box, donc c'est la taille de l'ensemmble des enfants.
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
    setSize ( sf::Vector2f taille ) { m_taille = taille ; };


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
    /// \brief La gestion des �v�nements utilisateurs.
    ///
    ///  G�re les entr�es claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les �l�ments.
    ///
    /// Actualiser les diff�rents �l�ments du ou des �crans actifs.
    /// \param deltaT          Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ( float deltaT ) ;

    /////////////////////////////////////////////////
    /// \brief Rendre les �l�ments.
    ///
    /// Dessiner les diff�rents �l�ments du ou des �crans actifs.
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

    // Contenant
    std::shared_ptr<Groupe>         m_grpContenant;     ///<
    std::shared_ptr<Groupe>         m_grpContenu;       ///<  Groupe des �l�ments du contenu de la Fenetre. ne s'affiche pas directment, est dessin� dans m_spriteContenant
    std::shared_ptr<sf::Sprite>     m_spriteContenant;  ///<  Le sprite qui affiche le contenu de la fenetre.

    // UI
    std::shared_ptr<Groupe>         m_UI;               ///<  les �l�ments d'interface du gadget
    std::shared_ptr<BoutonSlide>    m_slideVerti;       ///< le bouton du slide vertical
    std::shared_ptr<BoutonSlide>    m_slideHori;        ///< le bouton du slide horizontal



};
};


////////////////////////////////////////////////////////////
/// \class gui::Contenant
/// \ingroup interface
///
/// Contient des �l�ments et g�re un d�filement quand contenant est plus grand que contenu
///
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////







#endif // CONTENANT_H
