#ifndef ACTION_H
#define ACTION_H


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <functional>   // function
#include <utility>      // pair
#include <list>         // list
#include <map>         // map


namespace gui {

/////////////////////////////////////////////////
/// \enum Evenements
/// \brief enumeration des differents dtype d'�venements.
///
/////////////////////////////////////////////////
enum Evenements {
      onGRelache            ///<  Relache le bouton gauche de la souris.
    , onGRelacheDehors      ///<  Relache le bouton gauche de la souris.
    , onGPress              ///<  Presse le bouton gauche de la souris.
    , onDRelache            ///<  Relache le bouton droit de la souris.
    , onDRelacheDehors      ///<  Relache le bouton droit de la souris.
    , onDPress              ///<  Presse le bouton droit de la souris.
    , onMRelache            ///<  Relache le bouton du milieu de la souris.
    , onMRelacheDehors      ///<  Relache le bouton du milieu de la souris.
    , onMPress              ///<  Presse le bouton du milieu de la souris.
    , onMRollUp             ///<  Roule vers le haut le bouton du milieu de la souris.
    , onMRollDown           ///<  Roule vers le bas le bouton du milieu de la souris.
    , onEntre               ///<  Survol.
    , onSort                ///<  Quitte le survol.
    , onDblClique           ///<  Double clique
    , onChangeEtat          ///<  quand BoutonACocher change d'�tat
    , onFerme               ///<  Quand on ferme une fenetre.
    , onOuvre               ///<  Quand on ferme une fenetre.
};


/////////////////////////////////////////////////
/// \brief Classe virtuelle permetant de lier des �venements � des fonctions.
///
/// G�re les �venements, permet de d�clencher des fonctions associ�es � des �v�nements ...
///
/////////////////////////////////////////////////
class Action
{
    public:

        //D�clarations de types des fonction lambda que l'on associe au evenements declench�s
        using   FuncType = std::function<void()>;                               ///< la fonction lambda associ� aux declenchements des evenements.
        static  FuncType    defaultFunc;                                        ///< type par defaut de la fonction lambda.
        typedef  std::map< sf::Keyboard::Key    , FuncType >      evtClavier;   ///< Collecteur d'�venements clavier
        typedef  std::map< Evenements           , FuncType >      evtSouris;    ///< collecteur d'�venement d�clench� par nos gui::Evenements (souris, fenetre ..)

        /////////////////////////////////////////////////
        /// \brief Ajoute un ecouteur d'evenement associ� � une fonction lambda(FuncType) � executer lors du d�clenchement de l'evenement.
        ///
        /// \param evt          Un evenement de la liste Evenements.
        /// \param fonction     la fonction lambda associ�.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        lier    ( Evenements evt ,      const FuncType& fonction);

        /////////////////////////////////////////////////
        /// \brief Ajoute un ecouteur d'evenement associ� � une fonction lambda(FuncType) � executer lors du d�clenchement de l'evenement.
        ///
        /// \param touche          Une touche du clavier sf::Keyboard::Key.
        /// \param fonction     la fonction lambda associ�.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        lier    ( sf::Keyboard::Key  touche ,      const FuncType& fonction);

        /////////////////////////////////////////////////
        /// \brief supprimer un ecouteur d'�venement.
        ///
        /// \param evt        Un evenement souris de la liste _evtsSouris..
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        delier  ( Evenements evt );

        /////////////////////////////////////////////////
        /// \brief supprimer un ecouteur d'�venement clavier.
        ///
        /// \param touche        Une touche du clavier sf::Keyboard::Key.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        delier  ( sf::Keyboard::Key  touche);

    protected:

        /////////////////////////////////////////////////
        /// \brief D�clencher la fonction associ� � l'�venement.
        ///
        /// \param evt        L'evenement souris � declencher.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        void declencher ( Evenements evt );

        /////////////////////////////////////////////////
        /// \brief La gestion des �v�nements utilisateurs.
        ///
        /// \param event  les �v�nements claviers
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        bool traiter_evenements   ( const sf::Event& event );

        /////////////////////////////////////////////////
        // Les membres
        /////////////////////////////////////////////////
        evtSouris       _evtsSouris;    ///< La liste des evenements souris enregistr�s
        evtClavier      _evtsClavier;   ///< La liste des evenements Claviers enregistr�s


};// fin class action
};// fin du namespace gui




#endif // ACTION_H


////////////////////////////////////////////////////////////
/// \class gui::Action
/// \ingroup interface
///
/// \see sf::Shape, sf::CircleShape, sf::ConvexShape
///
////////////////////////////////////////////////////////////
