/**
* \file     Application.h
* \brief    La classe principale du programme.
* \author   Christophe Pages
* \version  0.1
* \date     2015
* \details  Programme minimal gérant differents écrans (intro, accueil, jeu, options...)
*/


#ifndef APPLICATION_H
#define APPLICATION_H

/////////////////////////////////////////////////
//  Headers
/////////////////////////////////////////////////
#include <Ecran.h>
#include <Gestion_ecrans.h>
#include <SFML/Graphics.hpp>
#include <vector>


namespace app {  ///<  app Espace de l'application.

class Ecran;

/////////////////////////////////////////////////
/// \class  Application
/// \brief  La classe de base du programme.
///
/// Gère les différents écrans du programme
/// (écran d'introduction, accueil, pause, écran du jeu ....)
/////////////////////////////////////////////////
class Application
{
    public:

        /////////////////////////////////////////////////
        /// \brief Constructeur
        ///
        /////////////////////////////////////////////////
        Application();

        /////////////////////////////////////////////////
        /// \brief Destructeur
        ///
        /////////////////////////////////////////////////
        virtual ~Application();

    public:

        /////////////////////////////////////////////////
        /// \brief La boucle principale.
        ///
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void executer();

        /////////////////////////////////////////////////
        /// \brief La gestion des évènements utilisateurs.
        ///
        ///  Gère les entrées claviers, souris, fenetre ...
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void traiter_evenements ();

        /////////////////////////////////////////////////
        /// \brief Actualiser les éléments.
        ///
        /// Actualiser les différents éléments du ou des écrans actifs.
        /// \param deltaT          Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void actualiser ( float deltaT );

        /////////////////////////////////////////////////
        /// \brief Rendre les éléments.
        ///
        /// Dessiner les différents éléments du ou des écrans actifs.
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        void dessiner ( );

        /////////////////////////////////////////////////
        /// \brief renvois la fenetre sfml de l'application
        ///
        /// \return la fenetre sfml de l'application
        ///
        /////////////////////////////////////////////////
        sf::RenderWindow&    getFenetre();

    private:

        /////////////////////////////////////////////////
        /// Les membres
        /////////////////////////////////////////////////
        Gestion_ecrans      m_ecrans;    ///< Le gestionnaire des écrans.
        sf::RenderWindow    m_fenetre;   ///< La fenêtre SFML

};
}; // fin namespace app


#endif // APPLICATION_H


////////////////////////////////////////////////////////////
/// \class app::Application
/// \defgroup application Module pour Application
///
/// Manipule les différents écrans de l'application à travers une boucle principale,
/// coeur de l'application, en simplifiant légèrement:
/// \li Ecouter les évenements utilisateurs ( claviers, cliques...).
/// \li Actualiser les parametres de tout les éléments.
/// \li Dessiner les éléments en vue dans la fenetre
///
/// C'est le gestionnaire des écrans (m_ecrans) qui se charge du traitement de la pile des écrans.
///
/// Quand il n'y a plus d'écrans dans la pile, l'application se ferme.
///
/// \see app::Ecran, app::EcranDemo, app::Gestion_ecrans
///
////////////////////////////////////////////////////////////
