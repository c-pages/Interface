#ifndef BOUTONTEXTE_H
#define BOUTONTEXTE_H

#include <gadgets\Bouton.h>
#include <gadgets\Label.h>

namespace gui {

class Label;

/////////////////////////////////////////////////
/// \brief Gadget, bouton rectangulaire (gui::Bouton) combiné à un Label (gui::texte).
///
/////////////////////////////////////////////////
class BoutonTexte : public Bouton
{

public:

    /////////////////////////////////////////////////
    /// \brief Constructeur défaut
    ///
    /// Creer le bouton avec la possibilité de définir le texte affiché.
    ///
    /// \param texte le texte du bouton. (optionnel)
    ///
    /////////////////////////////////////////////////
    BoutonTexte( std::string     texte ="" );

    /////////////////////////////////////////////////
    /// \brief  Constructeur a partir
    ///
    /// \param skin  le skin à utilisé pour ce bouton.
    /// \param texte le texte du bouton. (optionnel)
    /// \return
    ///
    /////////////////////////////////////////////////
    BoutonTexte ( std::shared_ptr<Skin>  skin
                , std::string   texte = "" );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~BoutonTexte();

    /////////////////////////////////////////////////
    /// \brief Definir le texte du bouton.
    ///
    /// \param texte le texte du bouton.
    ///
    /////////////////////////////////////////////////
    void
    setTexte   ( std::string   texte ) { m_lblTexte->setTexte( texte ); };

    /////////////////////////////////////////////////
    /// \brief Acceder au texte du bouton.
    ///
    /// \return la taille
    ///
    /////////////////////////////////////////////////
    std::string
    getTexte   ( ) { return m_lblTexte->getTexte(); };


    /////////////////////////////////////////////////
    /// \brief Ajuster la taille du bouton au texte du bouton (en tenant compte de la dimension de la bordure).
    ///
    /////////////////////////////////////////////////
    void
    ajusterAuTexte   ();

    /////////////////////////////////////////////////
    /// \brief Definir la taille du bouton.
    ///
    /// \param taille     La nouvelle taille.
    ///
    /////////////////////////////////////////////////
    virtual     void
    setSize   ( sf::Vector2f   taille );

    /////////////////////////////////////////////////
    /// \brief Definir le skin de reference du bouton.
    ///
    /// \param skin     La nouvelle taille.
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin> skin );

    /////////////////////////////////////////////////
    /// \brief Actualise le style du label
    ///
    /////////////////////////////////////////////////
    virtual void
    majGeom( );

    /////////////////////////////////////////////////
    /// \brief Rendre les éléments.
    ///
    /// Dessiner les différents éléments du ou des écrans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    draw( sf::RenderTarget& target, sf::RenderStates states ) const;

private:

    /////////////////////////////////////////////////
    /// \brief initialisation du gadget.
    ///
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    init ();


protected:
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    std::shared_ptr<Label>  m_lblTexte;     ///< pointeur vers le label.


};

};
#endif // BOUTONTEXTE_H

////////////////////////////////////////////////////////////
/// \class gui::BoutonTexte
/// \ingroup interface
///
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////


