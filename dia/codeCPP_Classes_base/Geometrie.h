#ifndef GEOMETRIE__H
#define GEOMETRIE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
/// \brief 
///
/////////////////////////////////////////////////
class Geometrie : public gui::Transformable, public gui::Drawable {
    
    /////////////////////////////////////////////////
    // Les methodes
    /////////////////////////////////////////////////
    
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par defaut
    ///
    /////////////////////////////////////////////////
    Geometrie ();

    /////////////////////////////////////////////////
    /// \brief Acceder à la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f getPosAbs () const;

    /////////////////////////////////////////////////
    /// \brief Définir la taille du gadget (m_taille, qui sert de cadre pour dessiner le gadget.)
    ///
    /// \param taille		 
    /////////////////////////////////////////////////
    void setSize (sf::Vector2i taille);

    /////////////////////////////////////////////////
    /// \brief Acceder à la taille du gadget (m_taille).
    ///
    /////////////////////////////////////////////////
    sf::Vector2i getSize () const;

    /////////////////////////////////////////////////
    /// \brief Acceder à la BB du gadget en coordonnées local (m_localBounds)..
    ///
    /////////////////////////////////////////////////
    sf::floatRect getLocalBounds () const;

    /////////////////////////////////////////////////
    /// \brief  Acceder à la BB du gadget en coordonnées global (m_globalBounds).
    ///
    /////////////////////////////////////////////////
    sf::floatRect getGlobalBounds () const;

    /////////////////////////////////////////////////
    /// \brief S'aligner sur un autre gadget.
    ///
    /// \param cible		 gadget sur lequel s'aligner.
    /////////////////////////////////////////////////
    void Aligner (ptr<Gadget> cible);

    /////////////////////////////////////////////////
    /// \brief  Test pour savoir si le point (x,y) survol le gadget.
    ///
    /// \param x		 
    /// \param y		 
    /////////////////////////////////////////////////
    bool Contient (float x, float y) const;

    /////////////////////////////////////////////////
    /// \brief Actualiser les membres bounds local et global.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();

    void setSkin (shared_ptr<Skin> skin);

protected:
    void init_skin ();

    
    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////
    
private:
    sf::Vector2i m_taille;    ///<  la taille permet d'organiser la disposition des éléments graphiques du gadget.    
    sf::floatRect m_localBounds;    ///<  la rectangle anglobant du gadget en coordonnés locales.    
    sf::floatRect m_globalBounds;    ///<  la rectangle anglobant du gadget en coordonnés globales.    
    std::shared_ptr<Skin> m_skin;    ///<  pointeur vers le skin du gadget    
};

} // fin namespace gui

#endif


////////////////////////////////////////////////////////////
/// class Geometrie
/// ingroup 
///
/// see 
///
////////////////////////////////////////////////////////////
