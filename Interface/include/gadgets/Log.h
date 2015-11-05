#ifndef LOG_H
#define LOG_H



/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>
#include <string>

namespace gui
{

class Label;




/////////////////////////////////////////////////
/// \brief Gadget, affichage de l'historique d'événements
///
/// permet l'affichage d'un historique d'évenements, et peut être un jour avec une entrée utilisateur facon invite de commande
/// s'active avec la touche ² ?
/// pour associer le Log à un printLog unique, on ne va pouvoir avoir qu'une seule instance de log dans un membre static
///
/////////////////////////////////////////////////
class Log :  public Gadget
{
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    Log();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    ~Log();

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    std::string
    getTexte();

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    void
    setTexte ( std::string txt );



    /////////////////////////////////////////////////
    /// \brief Définie le skin du Label.
    ///
    /// \param skin   Le skin à appliquer (Configuration::Styles).
    ///
    /// return Rien
    ///
    /////////////////////////////////////////////////
    virtual void
    setSkin( std::shared_ptr<Skin>    skin );


















    /////////////////////////////////////////////////
    /// \brief fonction static pour recuperer une instance du log (unique)
    ///
    /////////////////////////////////////////////////
    static std::shared_ptr<Log>
    Instance() ;


    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param
    /// \param
    /// \return
    ///
    /////////////////////////////////////////////////
    static void
    print ( std::string txt );



 protected:


    /////////////////////////////////////////////////
    // Les Membres
    /////////////////////////////////////////////////

 public:

    static std::shared_ptr<Log>                      ms_log;     ///<    l'instance unique et static du log.

 private:


    std::shared_ptr<Label>          m_lbl;      ///<    le gui::Label dans lequel on affiche notre log.

    std::string                     m_prefixe;  ///<    les prefixe qui débute chaque ligne
    //sf::Time


//
//
//typedef  Log::print  pLog;



 };



 ////////////////////////////////////////////////////////////
 /// \class gui::Log
 /// \ingroup  interface
 ///
 /// exemple :
 /// \code
 /// \endcode
 /// \see
 ///
 ////////////////////////////////////////////////////////////




} // fin namespace gui


#endif // LOG_H
