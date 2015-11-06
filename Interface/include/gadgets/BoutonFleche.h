#ifndef BOUTONFLECHE_H
#define BOUTONFLECHE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>



namespace gui
{

class ChampTexte;
class Bouton;

/////////////////////////////////////////////////
/// \brief Gadget, permet de controler une valeur numerique avec deux fl�che � cot� d'un Champ de saisie de texte li� � la valeur.
///
/// \todo � developper.
///
/////////////////////////////////////////////////
class BoutonFleche : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut
    ///
    /////////////////////////////////////////////////
    BoutonFleche();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~BoutonFleche();


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
    /// \brief initialiser les elements de l'UI de ce gadget.
    ///
    /////////////////////////////////////////////////
    void
    initUI();

    /////////////////////////////////////////////////
    /// \brief Mettre � jour les g�motries du gadget
    ///
    /////////////////////////////////////////////////
    void
    majGeom (  )  ;


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
    /// \brief acceder � la taille du gadget
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize ( ) const { return m_taille; };


    /////////////////////////////////////////////////
    /// \brief definir la taille du gadget
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille ) { m_taille = taille; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief Definir la valeur du gadget
    ///
    /////////////////////////////////////////////////
    void
    setVal ( float val );


    /////////////////////////////////////////////////
    /// \brief acceder � la valeur du gadget
    ///
    /////////////////////////////////////////////////
    float
    getVal ( ) { return m_valeur; };

    /////////////////////////////////////////////////
    /// \brief Definir la valeur du gadget
    ///
    /////////////////////////////////////////////////
    void
    setPrecision ( float val ) { m_precision = val; };


    /////////////////////////////////////////////////
    /// \brief acceder � la valeur du gadget
    ///
    /////////////////////////////////////////////////
    float
    getPrecision ( ) const { return m_precision; };




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
    float                           m_valeur;   ///< la valeur du gadget
    float                           m_precision;    ///< l'unit� de notre valuer, "l'echelle"
    std::shared_ptr<ChampTexte>     m_champ;    ///< le champ de texte du gadget.
    std::shared_ptr<Bouton>         m_btnPlus;  ///< le Bouton plus.
    std::shared_ptr<Bouton>         m_btnMoins; ///< le Bouton moins.

    sf::Vector2f                    m_taille;   ///<  Le taille de la fenetre.


    FuncType                        m_fctPlus;  ///<  fonction pour manipuler la valeur.
    FuncType                        m_fctMoins; ///<  fonction pour manipuler la valeur.
    FuncType                        m_fctChange;///<  fonction pour manipuler la valeur.
};

////////////////////////////////////////////////////////////
/// \class gui::BoutonFleche
/// \ingroup  interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////



} // fin namespace gui



#endif // BOUTONFLECHE_H
