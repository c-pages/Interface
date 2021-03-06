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

    enum TypeEntree {    ///<  les differents types de champ de saisie.
        sans,       ///< champ de saisie sans limitation.
        chiffres    ///< champ de saisie de chiffres uniquement.
    };

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /// \param texte    le texte � afficher de base dans le champ. (optionnel)
    /// \param taille   la taille du gadget. (optionnel)
    ///
    /////////////////////////////////////////////////
    ChampTexte  ( sf::Vector2f              taille = { 100, 20 }
                , std::shared_ptr<Skin>     skin   = std::shared_ptr<Skin> (new Skin ()) );

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
    /// \brief Definir la taille
    ///
    /// \param taille
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille );



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
    /// \brief D�finie le skin du Label.
    ///
    /// \param skin   Le skin � appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin>    skin );

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    std::string
    getTexte();

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    void
    setTexte ( std::string txt );


    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    void
    setType ( TypeEntree type ) { m_type = type ; };



    void
    initLocalSkin ();


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
    TypeEntree                      m_type;         ///< le type du champ de saisie.

    std::shared_ptr<Groupe>         m_grpUI;        ///<  Le groupe contenant l'interface de la fenetyre (boutons, titre)
    std::shared_ptr<Label>          m_lbl;          ///< pointeur vers le label.
    std::shared_ptr<BoutonEncoche>  m_btn;          ///< pointeur vers le bouton.
    std::string                     m_texteBack;    ///< version du texte avant la modification, pour pouvoir annuler la midif avec la touche Echappe.

    std::shared_ptr<Skin>           m_skinBtn;      ///<  Le skin pour les boutons
    sf::RectangleShape              m_curseur;      ///< le curseur texte

    sf::Clock                       m_timerClignot; ///< une horloge pour faire clignoter le curseur
    bool                            m_clignot;      ///< une horloge pour faire clignoter le curseur

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
