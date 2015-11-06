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
    icoMngr.charger( Icone::Fermer      , "../Interface/media/img/ico_fermer.png" );
    icoMngr.charger( Icone::FlecheBas   , "../Interface/media/img/ico_flecheBas.png" );
    icoMngr.charger( Icone::FlecheHaut  , "../Interface/media/img/ico_flecheHaut.png" );
}


} // fin namespace gui
