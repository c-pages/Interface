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
/// \todo � r�soudre :
///     -   le relache hors du bouton s'active meme quand on a pas cliquer dessus avant.
///     -   pareil pour le double clique.
///
/////////////////////////////////////////////////
class Bouton : public Gadget
{

public:

    /////////////////////////////////////////////////
    /// \brief Les Diff�rents �tats du gadget.
    ///
    /////////////////////////////////////////////////
    enum EtatBouton {
        desactive,  ///<  visible mais inactif.
        repos,      ///<  en attente d'interaction.
        survol,     ///<  quand la souris le survol.
        press       ///<  quand un bouton est cliqu�.
    };


public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /////////////////////////////////////////////////
    Bouton();

    /////////////////////////////////////////////////
    /// \brief Constructeur en definisant un style
    ///
    /// \param skin       Le skin � appliquer (Style).
    ///
    /////////////////////////////////////////////////
    Bouton( std::shared_ptr<Skin>  skin );


    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Bouton();


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
    getSize ( ) ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getLocalBounds ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \return  La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getGlobalBounds ( );

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
    /// \brief Definir l'�paisseur du cadre.
    ///
    /// \param epaisseur     La nouvelle �paisseur du cadre.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setOutlineThickness  ( float epaisseur );

    /////////////////////////////////////////////////
    /// \brief D�finie le skin du Label.
    ///
    /// \param skin   Le skin � appliquer (Configuration::Styles).
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
    /// \brief Acceder � la bordure du bouton
    ///
    /// \return m_bordure
    ///
    /////////////////////////////////////////////////
    float
    getBordure  ( ) { return m_bordure; };



    /////////////////////////////////////////////////
    /// \brief La gestion des �v�nements utilisateurs.
    ///
    ///  G�re les entr�es claviers, souris, fenetre ...
    ///
    /// \param event evenement SFML se transmettant depuis l'application
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    traiter_evenements ( const sf::Event& event );

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
    /// \brief Actualiser les �l�ments.
    ///
    /// Actualiser les diff�rents �l�ments du ou des �crans actifs.
    ///
    /// \param deltaT          Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    actualiser ( float deltaT ) override;

    /////////////////////////////////////////////////
    /// \brief Rendre les diff�rents �l�ments du ou des �crans actifs.
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
    // Les membres
    /////////////////////////////////////////////////
    EtatBouton              m_etat;             ///< L'�tat du bouton.
    EtatBouton              m_etatBack;         ///< L'�tat du bouton la frame d'avant, pour verifier si changement d'�tat.
    std::shared_ptr<Image>  m_fond;             ///< Le rectangle du fond du bouton.
    sf::Clock               m_clock_dblClique;  ///< Compteur temps pour double clique.
    bool                    m_1erClick;         ///< bool double clique, true lors du 1er clique, false a la fin du temps ou apres second clique.
    float                   m_bordure;          ///< l'espace de bordure (pour gui::boutonTexte, gui::BoutonCoher ..).

    /////////////////////////////////////////////////
    // Les membres static
    /////////////////////////////////////////////////

    static  Gadget*     ms_btnSurvol;    ///< le bouton qu'on est en train de survoler, pour eviter d'en avoir plusieurs en meme temps quand ils sont l'un sur l'autre.
    static  Gadget*     ms_btnPress;     ///< le bouton qu'on est en train de presser, pour quand le relache on sache sur lequel on �tait...

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


