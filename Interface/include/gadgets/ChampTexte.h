#ifndef CHAMPTEXTE_H
#define CHAMPTEXTE_H


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>
#include <Skin.h>


namespace gui
{

class BoutonEncoche;
class Label;
class Groupe;





/////////////////////////////////////////////////
/// \brief Gadget , champ de saisie de texte
///
/// \todo ... en developpement ...
///
/////////////////////////////////////////////////
class ChampTexte : public Gadget
{
public:

    enum Types {


    };

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /// \param texte    le texte à afficher de base dans le champ. (optionnel)
    /// \param taille   la taille du gadget. (optionnel)
    ///
    /////////////////////////////////////////////////
    ChampTexte  ( sf::Vector2f              taille = { 100, 20 }
                , std::shared_ptr<Skin>     skin   = new Skin () );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~ChampTexte();


    /////////////////////////////////////////////////
    /// \brief initialiser les elements de l'UI de ce gadget.
    ///
    /////////////////////////////////////////////////
    void
    initUI();

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
    /// \brief Définie le skin du Label.
    ///
    /// \param skin   Le skin à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin>    skin );


void
initLocalSkin ();


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

private:

    /////////////////////////////////////////////////
    // Les Membres
    /////////////////////////////////////////////////
    std::shared_ptr<Groupe>         m_grpUI;        ///<  Le groupe contenant l'interface de la fenetyre (boutons, titre)
    std::shared_ptr<Label>          m_lbl;          ///< pointeur vers le label.
    std::shared_ptr<BoutonEncoche>  m_btn;          ///< pointeur vers le label.
    std::string                     m_texteBack;    ///< version du texte avant la modification, pour pouvoir annuler la midif avec la touche Echappe.

    std::shared_ptr<Skin>           m_skinBtn;      ///<  Le skin pour les boutons
    sf::RectangleShape              m_curseur;      ///< le curseur texte

    sf::Clock                       m_timerClignot;  ///< une horloge pour faire clignoter le curseur
    bool                            m_clignot;          ///< une horloge pour faire clignoter le curseur

};

} // fin namespace gui

////////////////////////////////////////////////////////////
/// \class gui::ChampTexte
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////






#endif // CHAMPTEXTE_H
