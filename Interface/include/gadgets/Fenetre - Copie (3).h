#ifndef FENETRE_H
#define FENETRE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>




namespace gui {

class Groupe;
class Label;
class BoutonTexte;
class Contenant;
class Image;

/////////////////////////////////////////////////
/// \brief
///
///
///
/////////////////////////////////////////////////
class Fenetre : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /////////////////////////////////////////////////
    Fenetre( sf::RenderWindow  *     fenetre );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~Fenetre();


    /////////////////////////////////////////////////
    /// \brief Definir la titre
    ///
    /// \param titre le nouveau titre de la fenetre
    ///
    /////////////////////////////////////////////////
    void
    setTitre ( std::string titre );

    /////////////////////////////////////////////////
    /// \brief Definir la taille
    ///
    /// \param taille la taille
    ///
    /////////////////////////////////////////////////
    void
    setSize ( sf::Vector2f taille ) { m_taille = taille ; };

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getLocalBounds ( ) const {} ;

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \return  La boundingBox
    ///
    /////////////////////////////////////////////////
    virtual sf::FloatRect
    getGlobalBounds ( ) const {} ;


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
    // Les Membres
    /////////////////////////////////////////////////
    sf::RenderWindow    *           m_fenetreSFML;  ///< la fenetre SFML.
    sf::Vector2f                    m_taille;       ///> la taille de la fenetre

    std::shared_ptr<Groupe>         m_grpUI;        ///<  les �l�ments d'interface du gadget
    std::shared_ptr<Label>          m_lblTitre;     ///<  le titre
    std::shared_ptr<BoutonTexte>    m_btnFermer;    ///<  les �l�ments d'interface du gadget
    std::shared_ptr<Contenant>      m_contenant;    ///<  le contenant
    std::shared_ptr<Image>          m_fond;         ///<  le fond


};
}; // fin namespace
////////////////////////////////////////////////////////////
/// \class gui::Fenetre
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////








#endif // FENETRE_H
