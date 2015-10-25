
#ifndef GUI_H
#define GUI_H

/////////////////////////////////////////////////
// Hearders
/////////////////////////////////////////////////
#include <Skin.h>
#include <Style.h>
#include <action.h>
#include <Gadget.h>
#include <gadgets/Image.h>          // --->    affiche image ou couleur
#include <gadgets/Label.h>          // --->    affiche txt
#include <gadgets/Groupe.h>         // --->    groupe de gadgets   grp
#include <gadgets/Bouton.h>         // --->    declenche des fcts
#include <gadgets/BoutonTexte.h>    // --->    declenche des fcts
#include <gadgets/BoutonCocher.h>   // --->    0 ou 1
#include <gadgets/Fenetre.h>        // --->    fenetre               grp  + btn:(drag, redim, fermer)



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
