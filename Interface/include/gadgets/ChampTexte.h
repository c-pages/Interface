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

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /// \param texte    le texte � afficher de base dans le champ. (optionnel)
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
    std::shared_ptr<Groupe>         m_grpUI;        ///<  Le groupe contenant l'interface de la fenetyre (boutons, titre)
    std::shared_ptr<Label>          m_lbl;          ///< pointeur vers le label.
    std::shared_ptr<BoutonEncoche>  m_btn;          ///< pointeur vers le label.

    sf::RectangleShape              m_curseur;      ///< le curseur texte

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
