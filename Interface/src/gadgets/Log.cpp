
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

    m_lbl =  std::shared_ptr<Label>   ( new Label    (  ) );
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
Log::setTexte ( std::string txt )
{
    m_lbl->setTexte( txt ) ;
};


///////////////////////////////////////////////////
void
Log::print( std::string txt )
{
//time_t t;
//
//
//
//struct tm tempsTM = { time(&t) };


    //std::cout << "la date et l'heure courante sont : "
    //<< ctime(&t))
    //<< std::endl;



//
//
//
//    // current date/time based on current system
//    time_t  maintenant = time(0);
//
//
//
//    tm *ltm = localtime(&maintenant);
//
//    // print various components of tm structure.
//    //cout << "Year: "<< 1900 + ltm->tm_year << endl;
//
//
//
//    std::string txt_heure =   "";// + ltm->tm_hour ;// + ":" + ltm->tm_min;
//






    // recuperer le texte déja là
    std::string txt_tmp = ms_log->getTexte();
    // ajouter le nouveau texte
    txt_tmp += ms_log->m_prefixe + " : " + txt + "\n";
    // l'envoyer au label
    ms_log->setTexte ( txt_tmp );


}

} // fin namespace gui
