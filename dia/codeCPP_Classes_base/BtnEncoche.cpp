/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnEncoche.h>



namespace gui {

/////////////////////////////////////////////////
BtnEncoche::BtnEncoche (ptr parent)
: m_etat ( repos )
, m_cocheEtat ( false )
, m_label ( new () )
, m_cocheIcone ( new () )
, m_fondIcone ( new () )
, m_bouton ( new () )
{
    
}


/////////////////////////////////////////////////
BtnEncoche::BtnEncoche (ptr parent, string texte, bool coché)
: m_etat ( repos )
, m_cocheEtat ( false )
, m_label ( new () )
, m_cocheIcone ( new () )
, m_fondIcone ( new () )
, m_bouton ( new () )
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::setCoche (bool )
{
    
}


/////////////////////////////////////////////////
bool BtnEncoche::getCoche () const
{
    
}


/////////////////////////////////////////////////
string BtnEncoche::setTexte ()
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::setCocheIcone (const sf::Texture* icone)
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::setFondIcone (const sf::Texture* )
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::actualiser ()
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::traiter_evenements (const sf::Event& evenement)
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::init ()
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::init_skin ()
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::init_interactions ()
{
    
}


/////////////////////////////////////////////////
void BtnEncoche::actualiser_bounds ()
{
    
}


} // fin namespace gui

