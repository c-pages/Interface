
/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/Log.h"
#include "gadgets/Label.h"
#include <time.h>
#include <memory.h>


namespace gui
{



// initialisations statics
std::shared_ptr<Log>     Log::ms_log = std::make_shared<Log> (  );



///////////////////////////////////////////////////
Log::Log()
: m_lbl ( new Label () )
, m_prefixe ( "log")
{


 //   ms_log = std::make_shared<Log> ( std::move( *this ) ) ;

    m_lbl =  std::shared_ptr<Label>   ( new Label    ( "\"Inser\" pour cacher/montrer.\n\n" ) );
    //m_lbl->setTexte
    ajouter( m_lbl );
    //ctor


    m_lbl->lier ( sf::Keyboard::Insert , [this]() {
          m_lbl->setVisible ( not m_lbl->estVisible () );
    });
};

///////////////////////////////////////////////////
Log::~Log()
{
    //dtor
}

std::shared_ptr<Log>
Log::Instance()
{
    return ms_log;
}


/////////////////////////////////////////////////
std::string
Log::getTexte()  {

    return m_lbl->getTexte() ;
};


/////////////////////////////////////////////////
void
Log::setSkin( std::shared_ptr<Skin>    skin )
{
    m_lbl->setStyle (skin->lblLog);

}


/////////////////////////////////////////////////
void
Log::setTexte ( std::string txt )
{
    m_lbl->setTexte( txt ) ;
};


///////////////////////////////////////////////////
void
Log::print( std::string txt )
{


    // recuperer le texte déja là
    std::string txt_tmp = ms_log->getTexte();
    // ajouter le nouveau texte
    txt_tmp += ms_log->m_prefixe + " : " + txt + "\n";
    // l'envoyer au label
    ms_log->setTexte ( txt_tmp );


}

} // fin namespace gui
