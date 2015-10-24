

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Style.h"
#include <iostream>

namespace gui
{

/////////////////////////////////////////////////
Style::Style()
: txt_police    ( sf::Font() )
, txt_style     ( sf::Text::Style::Regular )
, txt_taille    ( 12 )
, txt_couleur   ( sf::Color ( 200,200,200) )
, lgn_epaisseur ( 1 )
, lgn_couleur   ( sf::Color ( 255,255,255 , 20 ) )
, fnd_couleur   ( sf::Color ( 255,255,255 , 50  ) )
, fnd_texture   ( sf::Texture ())
, align         ( Alignements::Libre )
, ajust         ( Ajustements::Sans )
{
    txt_police.loadFromFile ( "media/polices/arial.ttf" );
}

/////////////////////////////////////////////////
Style::Style( const Style& source )
: txt_police    ( source.txt_police )
, txt_style     ( source.txt_style  )
, txt_taille    ( source.txt_taille )
, txt_couleur   ( source.txt_couleur )
, lgn_epaisseur ( source.lgn_epaisseur )
, lgn_couleur   ( source.lgn_couleur )
, fnd_couleur   ( source.fnd_couleur )
, fnd_texture   ( source.fnd_texture )
, align         ( source.align )
, ajust         ( source.ajust )
{

}

} // fin namspace gui
