#ifndef GADGET_H
#define GADGET_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <Action.h>
#include <Skin.h>

namespace gui
{


/////////////////////////////////////////////////
/// \brief Classe virtuelle, la base commune aux gadgets formant l'interface.
///
/////////////////////////////////////////////////
class Gadget : public Action , public sf::Drawable , public sf::Transformable
{

public:


    typedef     std::shared_ptr < Gadget >     ptr; ///<  definition du type des pointeurs de gadget

    /////////////////////////////////////////////////
    /// \brief Constructeur par defaut
    ///
    /////////////////////////////////////////////////
    Gadget  ( );

    /////////////////////////////////////////////////
    /// \brief  Constructeur avec un style existant
    ///
    /// \param  style   Le style à appliquer (Configuration::Styles).
    ///
    /////////////////////////////////////////////////
    Gadget  ( std::shared_ptr<Style>   style );

    /////////////////////////////////////////////////
    /// \brief  Constructeur avec un style existant
    ///
    /// \param  skin   Le skin à appliquer (Configuration::Skins).
    ///
    /////////////////////////////////////////////////
    Gadget  ( std::shared_ptr <Skin>    skin );


    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Gadget();

    /////////////////////////////////////////////////
    /// \brief Acceder à la taille du gadget
    ///
    /// \return   La taille
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille ){};

    /////////////////////////////////////////////////
    /// \brief Acceder à la taille du gadget
    ///
    /// \return   La taille
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize ( ){  return {0,0}; };

    /////////////////////////////////////////////////
    /// \brief Acceder à la position absolue (en remontant les ancetres).
    ///
    /// \return   La position absolue.
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getPosAbs ();

    /////////////////////////////////////////////////
    /// \brief Acceder à la boundingBox local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getLocalBounds(){ return sf::FloatRect (); };

    /////////////////////////////////////////////////
    /// \brief Acceder à la boundingBox global
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getGlobalBounds(){ return sf::FloatRect (); };

    /////////////////////////////////////////////////
    /// \brief Ajouter un enfant.
    ///
    /// \param    enfant          Le \e Gadget à ajouter à m_enfants.
    ///
    /// \return La Rien
    /// \todo     verifier que l'enfant est pas deja dans la liste ( cause erreur possible )
    ///
    /////////////////////////////////////////////////
    virtual     void
    ajouter ( ptr enfant );

    /////////////////////////////////////////////////
    /// \brief Définie le skin du Label.
    ///
    /// \param skin   Le skin à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin>    skin );

    /////////////////////////////////////////////////
    /// \brief Définie le style du Label.
    ///
    /// \param style       Le style à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setStyle( std::shared_ptr<Style>     style );

    /////////////////////////////////////////////////
    /// \brief Aligne le gadget sur un autre
    ///
    /// \param cible   le gadget sur lequel s'aligner.
    /// \param align   l'alignement sur la cible ( haut_gauche ...
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    void
    aligner (  Gadget& cible , Alignements    align  = Alignements::Ctre_Mili );

    /////////////////////////////////////////////////
    /// \brief Definir l'état du Gadget.
    ///
    /// \param val     bool.
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    setEnable ( bool val ) { m_enable = val; };

    /////////////////////////////////////////////////
    /// \brief Accesseur état du Gadget.
    ///
    /// \return true si le gadget est actif
    ///
    /////////////////////////////////////////////////
    bool
    isEnable (  ) { return m_enable ; };

    /////////////////////////////////////////////////
    /// \brief demande si le gadget est en attente de suppression
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    bool
    aSupprimer(){  return m_aSupprimer ; };

    /////////////////////////////////////////////////
    /// \brief Demander la suppression de ce gadget
    ///
    /// Il sera eliminé par son parent au debut de l'actualisation.
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void
    supprimer(){  m_aSupprimer = true; };

    /////////////////////////////////////////////////
    /// \brief overload annulant la fonction rotate
    ///
    /// ne fait rien du tout ! juste là pour bloquer la rotation sur les gadgets !
    /// C'est un peu tricky ce truc mais c'est simple et efficace.
    /// ca bloque le souci de zone de clique qui ne suivent pas les rotate...
    /// => rotate() n'est pas pris en compte.
    ///
    /////////////////////////////////////////////////
    virtual void
    rotate(float x )  { std::cout <<"ATTENTION: rotate() n'est pas pris en compte pour tout les gui::gadgets!\n"; } ;

protected:

    /////////////////////////////////////////////////
    /// \brief Renvois si le point (x,y) est contenu dans le gadget
    ///
    /// \param x
    /// \param y
    /// \return true si le point (x,y) est contenu par le gadget.
    ///
    /////////////////////////////////////////////////
    bool
    contient ( float x, float y );

    /////////////////////////////////////////////////
    /// \brief Actualise le model du Gadget
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    majFormes(){};


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



    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

protected:

    std::string             m_nom;          ///< le nom du gadget, (pour l'instant on s'en sert pas mais peut etre un jour...).
    Gadget*                 m_parent;       ///< le gadget m_parent.
    std::vector< ptr >      m_enfants;      ///< Les enfants du bouton.
    std::shared_ptr<Skin>   m_skin;         ///< le skin du gadget.
    std::shared_ptr<Style>  m_style;        ///< le style du gadget.
    bool                    m_enable;       ///< si le gadget est actif ou pas.
    bool                    m_aSupprimer;   ///< On le passe à true quand on veut supprimer ce gadget (il sera supprimé par son parent au debut de l'actualisation).
    bool                    m_besoinActua;  ///< Si on a changer un truc qui necessite d'actualiser la geometrie, couleur... du gadget (comme un resize ou pendant le survol d'un bouton par exemple).

};// fin de class Gadget
};// fin du namespace gui


/////////////////////////////////////////////////
// Include des templates *.inl
/////////////////////////////////////////////////
#include <Gadget.inl>


#endif // GADGET_H




////////////////////////////////////////////////////////////
/// \class gui::Gadget
/// \ingroup interface
///
/// hérite de sf::Transformable donc on peut utiliser les trucs SFML genre getPosition().
/// \see gui::Label, gui::Groupe
///
////////////////////////////////////////////////////////////
