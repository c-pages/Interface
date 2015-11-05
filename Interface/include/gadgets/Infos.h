#ifndef INFOS_H
#define INFOS_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui
{

class Label;

/////////////////////////////////////////////////
/// \brief Gadget, simple label renvoyant des infos.
///
/// Indique la position de la souris et le frame rate pour l'instant, pourra etre completé en fonction des besoins.
///
/////////////////////////////////////////////////
class Infos : public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    Infos( );


    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    Infos( std::shared_ptr <Skin>    skin );

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~Infos();

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


protected:

private:

    /////////////////////////////////////////////////
    // Les Membres
    /////////////////////////////////////////////////
    std::shared_ptr<Label>  m_lblMouseX;        ///< pointeur vers le label.
    std::shared_ptr<Label>  m_lblMouseY;        ///< pointeur vers le label.
    std::shared_ptr<Label>  m_lblMouseFps;      ///< pointeur vers le label.

    sf::Vector2i            m_mousePos;
    sf::Clock               m_clock;            ///< une horloge les fps
    int                     m_compteurFPS;      ///< une horloge les fps
    int                     m_FPS;              ///< une horloge les fps
};

////////////////////////////////////////////////////////////
/// \class gui::Infos
/// \ingroup interface
///
/// exemple :
/// \code
/// \endcode
/// \see
///
////////////////////////////////////////////////////////////






}; // fin namespace

#endif // INFOS_H
