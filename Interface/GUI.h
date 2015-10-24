
#ifndef GUI_H
#define GUI_H

/////////////////////////////////////////////////
// Hearders
/////////////////////////////////////////////////


//namespace gui
//{
//    class Gadget;
//    // definition du type des pointeurs de gadget
//    typedef     std::shared_ptr < Gadget >     ptr;
//}

#include <Skin.h>
#include <Style.h>
#include <action.h>
#include <Gadget.h>
#include <gadgets/Image.h>          // --->    affiche image ou couleur
#include <gadgets/Label.h>          // --->    affiche txt
#include <gadgets/Groupe.h>         // --->    groupe de gadgets   grp
#include <gadgets/Bouton.h>         // --->    declenche des fcts




//
////SaisieTexte                    // --->    Champs de saisie de texte
//
//#include <gadgets/BoutonTexte.h> // --->    declenche fct
////BoutonCurseur                     --->    de 0. � 1.
//#include <gadgets/BoutonCocher.h>//--->    0 ou 1
////barProgres                        --->    bar de chargement
//
//*============  groups     =========*/
//#include <gadgets/Groupe.h>      // --->    group invisible       grp
////liste                             --->    group list�           grp2D ( liste: �l�ment + param...  ) )  + btn:(drag, redim, fermer)
//
//*============  fenetres     =========*/
//#include <gadgets/Fenetre.h>     // --->    fenetre               grp  + btn:(drag, redim, fermer)
////fenetreQuestion                   --->    fenetre oui ou non    grp  + btn:(drag, oui, non)
////fenetreOnglets                    --->    1 onglet / 1 fenetre  grps + btn:(drag, redim, fermer, onglets)



#endif // GUI_H

////////////////////////////////////////////////////////////
/// \defgroup interface Module pour interface graphique
///
/// Elements d'interface graphique: Boutons, fen�tres, ...
///
////////////////////////////////////////////////////////////
