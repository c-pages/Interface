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
/// \brief La classe virtuelle commune aux gadgets formant l'interface.
///
/////////////////////////////////////////////////
class Gadget : public Action , public sf::Drawable , public sf::Transformable
{

public:

    // definition du type des pointeurs de gadget
    typedef     std::shared_ptr < Gadget >     ptr;

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
    Gadget  ( Style    style );

    /////////////////////////////////////////////////
    /// \brief  Constructeur avec un style existant
    ///
    /// \param  skin   Le skin à appliquer (Configuration::Skins).
    ///
    /////////////////////////////////////////////////
    Gadget  ( Skin    skin );


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
    /// \brief Définie le skin du Label.
    ///
    /// \param style   Le skin à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( Skin    skin ) {
        m_skin = skin ;
        updateStyle( );
    };

    /////////////////////////////////////////////////
    /// \brief Définie le style du Label.
    ///
    /// \param style       Le style à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setStyle( Style     style ) {
        std::cout << "setStyle\n";
        m_style = style ;
        updateStyle( );
    };

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
    aligner ( Gadget *cible , Alignements    align  = Alignements::Ctre_Mili );

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
    /// \brief overload de la fonction rotate
    ///
    /// permet de bloquer la rotation sur les gadgets
    ///
    /////////////////////////////////////////////////
    virtual void
    rotate(float x )  {} ;

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
    /// \brief Actualise le style du Gadget
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    updateStyle(){};


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
    virtual void actualiser ( float deltaT );

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

    std::string         m_nom;          ///< le nom du gadget, (pour l'instant on s'en sert pas mais peut etre un jour...).
    Gadget*             m_parent;       ///< le gadget m_parent.
    std::vector< ptr >  m_enfants;      ///< Les enfants du bouton.
    Skin                m_skin;         ///< le skin du gadget.
    Style               m_style;        ///< le style du gadget.
    bool                m_enable;       ///< l'état du gadget.
    bool                m_aSupprimer;   ///<

};// fin de class Gadget
};// fin du namespace gui

#include <Gadget.inl>

#endif // GADGET_H


////////////////////////////////////////////////////////////
/// \class gui::Gadget
/// \ingroup interface
///
/// \see gui::Label, gui::Groupe
///
////////////////////////////////////////////////////////////
