#ifndef BOUTON_H
#define BOUTON_H


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Gadget.h>

namespace gui {

class Image;

/////////////////////////////////////////////////
/// \brief Gadget, simple bouton rectangulaire
///
/// \todo résoudre quand il y a superposition de boutons, seulement celui du dessus doit reagir
///
/////////////////////////////////////////////////
class Bouton : public Gadget
{

public:

    /////////////////////////////////////////////////
    /// \brief Les Différents états du gadget.
    ///
    /////////////////////////////////////////////////
    enum EtatBouton {
        desactive,  ///<  visible mais inactif.
        repos,      ///<  en attente d'interaction.
        survol,     ///<  quand la souris le survol.
        press       ///<  quand un bouton est cliqué.
    };


public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    Bouton();

    /////////////////////////////////////////////////
    /// \brief Constructeur en definisant un style
    ///
    /// \param skin       Le skin à appliquer (Style).
    ///
    /////////////////////////////////////////////////
    Bouton ( std::shared_ptr<Skin>  skin
           , sf::Vector2f           taille = { 10 , 10 });


    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Bouton();


    /////////////////////////////////////////////////
    /// \brief Definir une texture pour l'icone du bouton.
    ///
    /// \param texture     La nouvelle texture.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    setIcone   ( const sf::Texture*   texture );


    /////////////////////////////////////////////////
    /// \brief Definir la taille du bouton.
    ///
    /// \param taille     La nouvelle taille.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void
    setSize   ( sf::Vector2f   taille );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la taille
    ///
    /// \return La taille
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize ( ) const ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getLocalBounds ( ) const;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \return  La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getGlobalBounds ( ) const;

    /////////////////////////////////////////////////
    /// \brief Definir Couleur du fond.
    ///
    /// \param color     La nouvelle Couleur du fond.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setFillColor ( sf::Color color );

    /////////////////////////////////////////////////
    /// \brief Definir Couleur du cadre.
    ///
    /// \param color     La nouvelle Couleur du cadre.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setOutlineColor  ( sf::Color color );

    /////////////////////////////////////////////////
    /// \brief Definir l'épaisseur du cadre.
    ///
    /// \param epaisseur     La nouvelle épaisseur du cadre.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setOutlineThickness  ( float epaisseur );

    /////////////////////////////////////////////////
    /// \brief Définie le skin du Label.
    ///
    /// \param skin   Le skin à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin>     skin );

    /////////////////////////////////////////////////
    /// \brief Definir la bordure du texte
    ///
    /// \param val la nouvelle valeur pour la bordure m_bordure.
    ///
    /////////////////////////////////////////////////
    void
    setBordure   ( float val  ) { m_bordure = val; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief Acceder à la bordure du bouton
    ///
    /// \return m_bordure
    ///
    /////////////////////////////////////////////////
    float
    getBordure  ( ) const { return m_bordure; } ;




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief La gestion du survol
    ///
    /// \param x
    /// \param y
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    test_declSurvol ( const sf::Event& event  );

    /////////////////////////////////////////////////
    /// \brief La gestion du survol
    ///
    /// \param x
    /// \param y
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    test_declPress ( const sf::Event& event   );

    /////////////////////////////////////////////////
    /// \brief La gestion du survol
    ///
    /// \param x
    /// \param y
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    test_declRelache ( const sf::Event& event   );

    /////////////////////////////////////////////////
    /// \brief La gestion du survol
    ///
    /// \param x
    /// \param y
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    test_declRouletteSouris ( const sf::Event& event   );



    void
    gerer_declenchements( const sf::Event& event );

    void
    gerer_etat( const sf::Event& event );


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

protected:

    /////////////////////////////////////////////////
    /// \brief Actualise le style du label
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    majGeom ( );

    /////////////////////////////////////////////////
    // Les membres static
    /////////////////////////////////////////////////
public:
    static  Gadget*     ms_btnSurvol;    ///< le bouton qu'on est en train de survoler, pour eviter d'en avoir plusieurs en meme temps quand ils sont l'un sur l'autre.
    static  Gadget*     ms_btnPress;     ///< le bouton qu'on est en train de presser, pour quand le relache on sache sur lequel on était...

protected:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    EtatBouton              m_etat;             ///< L'état du bouton.
    EtatBouton              m_etatBack;         ///< L'état du bouton la frame d'avant, pour verifier si changement d'état.
    bool                    m_bIcone;           ///< si on utilise une icone
    std::shared_ptr<Image>  m_icone;            ///< Le rectangle de l'icone du bouton. \todo getsion icone dans gui::Bouton, une image fixe avec en transparence m_fond qui change d'état
    std::shared_ptr<Image>  m_fond;             ///< Le rectangle du fond du bouton.
    sf::Clock               m_clock_dblClique;  ///< Compteur temps pour double clique.
    bool                    m_1erClick;         ///< bool double clique, true lors du 1er clique, false a la fin du temps ou apres second clique.
    float                   m_bordure;          ///< l'espace de bordure (pour gui::boutonTexte, gui::BoutonCoher ..).



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
//std::cout << "--- bouton ------------------- " << this << " ---> ";
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

#endif // BOUTON_H


////////////////////////////////////////////////////////////
/// \class gui::Bouton
/// \ingroup interface
///
/// exemple :
/// \code
/// \endcode
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////

















