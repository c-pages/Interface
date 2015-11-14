#ifndef EVTSSOURIS__H
#define EVTSSOURIS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////


namespace gui {

/////////////////////////////////////////////////
/// \brief les evenements de la souris qui déclenchent une fonction lambda associée.
///
/////////////////////////////////////////////////
enum EvtsSouris {
    onBtnG_DblClique,        ///< Double clique gauche
    onBtnG_Relache,        ///< Relache le bouton gauche de la souris.
    onBtnG_RelacheDehors        ///< Relache a coté du gadget avec le bouton gauche de la souris après avoir pressé dedans.
};

} // fin namespace gui

#endif
