#ifndef FENETRE_H
#define FENETRE_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

namespace gui {

class Groupe;
class Label;
class Bouton;
class Image;

/////////////////////////////////////////////////
/// \brief Gadget  permettant de rassembler des Gadgets au sein d'une Fenetre.
///
/////////////////////////////////////////////////
class Fenetre : public Gadget
{

public:

    Fenetre(    sf::RenderWindow  *     fenetre
            ,   std::shared_ptr<Skin>   skin = new Skin()
            ,   sf::Vector2f        taille  = { 100 , 100 } );

    virtual ~Fenetre();

    /////////////////////////////////////////////////
    /// \brief Definir la position de la fenetre
    ///
    /// \param pos position, c'est la du coin haut gauche de la fenetre, => prend en compte le decallage de m_bordure.
    ///
    /////////////////////////////////////////////////
    virtual void
    setPosition ( sf::Vector2f pos ) {
        Gadget::setPosition ( pos.x + m_bordure , pos.y + m_bordure  );
    };


    /////////////////////////////////////////////////
    /// \brief Definir la position de la fenetre
    ///
    /// \param pos position, c'est la du coin haut gauche de la fenetre, => prend en compte le decallage de m_bordure.
    ///
    /////////////////////////////////////////////////
    virtual void
    setPosition ( float x  ,  float y ) {
        Gadget::setPosition ( x + m_bordure , y + m_bordure  );
    };





    /////////////////////////////////////////////////
    /// \brief Definir la taille du contenu
    ///
    /// \param taille, c'est la taille du cadre du contenu, sans les boutons de la fenetres.
    ///
    /////////////////////////////////////////////////
    virtual void
    setSize ( sf::Vector2f taille ) {
        m_taille = taille ;
        majGeom ();
    };

    /////////////////////////////////////////////////
    /// \brief Acceder � la taille de la fenetre
    ///
    /// \return la taille reel de la fenetre avec boutons..
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f
    getSize ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en local
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getLocalBounds ( );

    /////////////////////////////////////////////////
    /// \brief Accesseur de la boundingBox en global
    ///
    /// \return La boundingBox
    ///
    /////////////////////////////////////////////////
    sf::FloatRect
    getGlobalBounds ( );
/*
    /////////////////////////////////////////////////
    /// \brief ajouter un enfant
    ///
    ///  Pour une fenetre on rajoute l'enfant dans le groups de contenu.
    ///
    /// \param enfant
    ///
    /////////////////////////////////////////////////
    virtual void
    ajouter( ptr enfant );*/

    /////////////////////////////////////////////////
    /// \brief Definir l'epaisseur de la bordure
    ///
    /// la bordure contient les boutons de recadrage
    ///
    /// \param bordure
    ///
    /////////////////////////////////////////////////
    void
    setBordure ( float bordure ) { m_bordure = bordure; majGeom(); };

    /////////////////////////////////////////////////
    /// \brief renvois la bordure
    ///
    /// \return la bordure
    ///
    /////////////////////////////////////////////////
    float
    getBordure (  ) { return m_bordure ; };

private:



    /////////////////////////////////////////////////
    /// \brief Initialiser les gadgets ( boutons, titre...).
    ///
    /////////////////////////////////////////////////
    virtual void
    creerUI();


    /////////////////////////////////////////////////
    /// \brief mais � jour les styles des �l�ments de la fen�tre.
    ///
    /////////////////////////////////////////////////
    virtual void
    updateStyle( );

    /////////////////////////////////////////////////
    /// \brief Mettre � jour les g�motries de la fen�tre
    ///
    /////////////////////////////////////////////////
    void
    majGeom (  )  ;


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
    // Les membres
    /////////////////////////////////////////////////

    sf::RenderWindow *              m_fenetreSFML;          ///<  pointeur vers la fenetre SFML (pour la position absolue de la souris , pour les manips de la fenetre).
    float                           m_bordure;              ///<  Le taille de la bordure du cadre.
    sf::Vector2f                    m_taille;               ///<  Le taille de la fenetre.
    sf::Vector2f                    m_tailleContenu;        ///<  Le taille du contenu.

    std::shared_ptr<Groupe>         m_UI;
    // les gadgets de la fen�tre
    std::shared_ptr<Groupe>         m_grpContenu;           ///<  Groupe des �l�ments du contenu de la Fenetre. ne s'affiche pas directment, est dessin� dans m_spriteContenant
    std::shared_ptr<Image>          m_CadreContenu;         ///<  Groupe des �l�ments du contenu de la Fenetre.
    std::shared_ptr<sf::Sprite>     m_spriteContenant;        ///<  Le sprite qui affiche le contenu de la fenetre.
    std::shared_ptr<Image>          m_fond;                 ///<  Le rectangle du fond.

//    std::shared_ptr<BoutonSlide>    m_boutonSlide;

};

};

#endif // FENETRE_H


////////////////////////////////////////////////////////////
/// \class gui::Fenetre
/// \ingroup interface
///
/// Les differents axes d'une fen�tre:
/// \code
///
///
///    // ///// Position des reperes dans la fenetre ///////////////////////////////////
///    //                                                                             //
///    //                HORIZ_...                                                    //
///    //                                                                             //
///    //  VERTI_...     0    1                       2    3                          //
///    //                |    |                       |    |                          //
///    //      0 ---     |----|-----------------------|----|  ---                     //
///    //                |    |                       |    |      m_bordure           //
///    //      1 ---     |----|-----------------------|----|  ---                     //
///    //                |    |0,0                    |    |                          //
///    //                |    |                       |    |                          //
///    //                |    |                       |    |                          //
///    //                |    |        Contenu        |    |      taille.y            //
///    //                |    |                       |    |                          //
///    //                |    |                       |    |                          //
///    //                |    |                       |    |                          //
///    //      2 ---     |----|-----------------------|----|  ---                     //
///    //                |    |                       |    |      m_bordure           //
///    //      3 ---     |----|-----------------------|----|  ---                     //
///    //                                                                             //
///    //                |    |                       |    |                          //
///    //               m_bordure      taille.x      m_bordure                        //
///    //                                                                             //
///    /////////////////////////////////////////////////////////////////////////////////
///
///
/// \endcode
/// \see gui::Gadget
///
////////////////////////////////////////////////////////////




