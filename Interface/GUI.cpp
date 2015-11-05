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
    icoMngr.charger( Icone::Fermer , "../Interface/media/img/ico_fermer.png" );
}


} // fin namespace gui
