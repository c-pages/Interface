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
/// \brief enumeration des differents dtype d'évenements.
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
    , onChangeEtat          ///<  quand BoutonACocher change d'état
    , onFerme               ///<  Quand on ferme une fenetre.
    , onOuvre               ///<  Quand on ferme une fenetre.
};


/////////////////////////////////////////////////
/// \brief Classe virtuelle permetant de lier des évenements à des fonctions.
///
/// Gère les évenements, permet de déclencher des fonctions associées à des évènements ...
///
/////////////////////////////////////////////////
class Action
{
    public:

        //Déclarations de types des fonction lambda que l'on associe au evenements declenchés
        using   FuncType = std::function<void()>;                               ///< la fonction lambda associé aux declenchements des evenements.
        static  FuncType    defaultFunc;                                        ///< type par defaut de la fonction lambda.
        typedef  std::map< sf::Keyboard::Key    , FuncType >      evtClavier;   ///< Collecteur d'évenements clavier
        typedef  std::map< Evenements           , FuncType >      evtSouris;    ///< collecteur d'évenement déclenché par nos gui::Evenements (souris, fenetre ..)

        /////////////////////////////////////////////////
        /// \brief Ajoute un ecouteur d'evenement associé à une fonction lambda(FuncType) à executer lors du déclenchement de l'evenement.
        ///
        /// \param evt          Un evenement de la liste Evenements.
        /// \param fonction     la fonction lambda associé.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        lier    ( Evenements evt ,      const FuncType& fonction);

        /////////////////////////////////////////////////
        /// \brief Ajoute un ecouteur d'evenement associé à une fonction lambda(FuncType) à executer lors du déclenchement de l'evenement.
        ///
        /// \param touche          Une touche du clavier sf::Keyboard::Key.
        /// \param fonction     la fonction lambda associé.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        lier    ( sf::Keyboard::Key  touche ,      const FuncType& fonction);

        /////////////////////////////////////////////////
        /// \brief supprimer un ecouteur d'évenement.
        ///
        /// \param evt        Un evenement souris de la liste _evtsSouris..
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        delier  ( Evenements evt );

        /////////////////////////////////////////////////
        /// \brief supprimer un ecouteur d'évenement clavier.
        ///
        /// \param touche        Une touche du clavier sf::Keyboard::Key.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        virtual void
        delier  ( sf::Keyboard::Key  touche);

    protected:

        /////////////////////////////////////////////////
        /// \brief Déclencher la fonction associé à l'évenement.
        ///
        /// \param evt        L'evenement souris à declencher.
        /// \return Rien.
        ///
        /////////////////////////////////////////////////
        void declencher ( Evenements evt );

        /////////////////////////////////////////////////
        /// \brief La gestion des évènements utilisateurs.
        ///
        /// \param event  les évènements claviers
        /// \return Rien
        ///
        /////////////////////////////////////////////////
        bool traiter_evenements   ( const sf::Event& event );

        /////////////////////////////////////////////////
        // Les membres
        /////////////////////////////////////////////////
        evtSouris       _evtsSouris;    ///< La liste des evenements souris enregistrés
        evtClavier      _evtsClavier;   ///< La liste des evenements Claviers enregistrés


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
