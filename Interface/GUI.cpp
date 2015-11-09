/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <../GUI.h>
#include <Utilitaires.h>



namespace gui
{


///////////////////////////////////////////////////
IconeManager    icoMngr;        ///< Gestionnaire des textures pour icones \todo verifer qu'on ne puisse pas en avoir plusieurs..




///////////////////////////////////////////////////
void
init()
{
    // init des icones
    icoMngr.charger( Icone::Fermer          , "../Interface/media/img/ico_fermer.png" );
    icoMngr.charger( Icone::FlecheBas       , "../Interface/media/img/ico_flecheBas.png" );
    icoMngr.charger( Icone::FlecheHaut       , "../Interface/media/img/ico_flecheHaut.png" );

    // init des curseurs
    icoMngr.charger( Curseur::redim_diag1   , "../Interface/media/img/curseur_fleches_diag1.png" );
    icoMngr.charger( Curseur::redim_diag2   , "../Interface/media/img/curseur_fleches_diag2.png" );
    icoMngr.charger( Curseur::redim_hori   , "../Interface/media/img/curseur_fleches_hori.png" );
    icoMngr.charger( Curseur::redim_vert   , "../Interface/media/img/curseur_fleches_verti.png" );
}


} // fin namespace gui
