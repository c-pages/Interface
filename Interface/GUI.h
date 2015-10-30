
#ifndef GUI_H
#define GUI_H

/////////////////////////////////////////////////
// Hearders
/////////////////////////////////////////////////

// styles
#include <Skin.h>
#include <Style.h>

// classes virtuelles
#include <Gadget.h>                     // --->    classe virtuelle élémentaire d'un gadget
#include <action.h>                     // --->    classe virtuelle pour gerer les événements d'un gadget
#include <UI.h>                         // --->    classe virtuelle pour gerer des éléments d'interface dans un gadget (ex: un bouton dans un gadget Fenetre)

// affichage simple
#include <gadgets/Image.h>              // --->    affiche image ou couleur
#include <gadgets/Label.h>              // --->    affiche txt

//boutons
#include <gadgets/Bouton.h>             // --->    declenche des fcts
#include <gadgets/BoutonTexte.h>        // --->    declenche des fcts
#include <gadgets/BoutonEncoche.h>      // --->    0 ou 1
#include <gadgets/BoutonSlide.h>        // --->    pour defilement de contenu dans le fenetres

//fenetre et groupes
#include <gadgets/Contenant.h>          // --->    groupe de gadgets   grp
#include <gadgets/Groupe.h>             // --->    groupe de gadgets   grp
#include <gadgets/Fenetre.h>            // --->    fenetre               grp  + btn:(drag, redim, fermer)
#include <gadgets/Fenetre_encastree.h>  // --->    fenetre encastrée sur un bord de la fenetre SFML



// NOTES //////////////////////////////////////////////////////////////////////////////
////SaisieTexte                    // --->    Champs de saisie de texte
//
////BoutonCurseur                     --->    de 0. à 1.
////barProgres                        --->    bar de chargement
//
//*============  groups     =========*/
//#include <gadgets/Groupe.h>      // --->    group invisible       grp
////liste                             --->    group listé           grp2D ( liste: élément + param...  ) )  + btn:(drag, redim, fermer)
//
//*============  fenetres     =========*/
//
////fenetreQuestion                   --->    fenetre oui ou non    grp  + btn:(drag, oui, non)
////fenetreOnglets                    --->    1 onglet / 1 fenetre  grps + btn:(drag, redim, fermer, onglets)
///////////////////////////////////////////////////////////////////////////////////////



#endif // GUI_H

////////////////////////////////////////////////////////////
/// \defgroup interface Module pour interface graphique
///
/// Elements d'interface graphique: Boutons, fenêtres, ...
///
////////////////////////////////////////////////////////////
