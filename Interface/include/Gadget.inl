#include "Gadget.h"

#include <iostream>


namespace gui {
//
//    template <typename  T>
//    void
//    Gadget::aligner ( T *cible ){
//
//        sf::Vector2f centreCible    = cible->getPosition();
//        centreCible += sf::Vector2f ( cible->getSize().x /2  , cible->getSize().y /2 );
//
//        sf::FloatRect   bb      = getBounds();
//        sf::Vector2f    centre  = sf::Vector2f  ( bb.left + getSize().x /2  ,   bb.top  + getSize().y /2 );
//
//        setPosition(      centreCible - centre  ) ;
//    }

//
//    template <typename  T>
//    void
//    Gadget::aligner ( T *cible , Alignements    newAlign ){
//
//        // distance a garder par rapport aux bords de la cible
//        float           ecart       = 2;
//
//        // valeurs pour la cible
//        sf::FloatRect   rect_cible   = cible->getBounds() ;
//
//        float    cbl_gauche  = rect_cible.left;
//        float    cbl_milieu  = rect_cible.left + rect_cible.width/2 ;
//        float    cbl_droite  = rect_cible.left + rect_cible.width;
//
//        float    cbl_haut    = rect_cible.top;
//        float    cbl_centre  = rect_cible.top + rect_cible.height/2;
//        float    cbl_bas     = rect_cible.top + rect_cible.height;
//
//        std::cout << "\n";
//        std::cout << "\n  cbl_gauche : " << cbl_gauche;
//        std::cout << "\n  cbl_milieu : " << cbl_milieu;
//        std::cout << "\n  cbl_droite : " << cbl_droite;
//        std::cout << "\n  cbl_haut : " << cbl_haut;
//        std::cout << "\n  cbl_centre : " << cbl_centre;
//        std::cout << "\n  cbl_bas : " << cbl_bas;
//        std::cout << "\n";
//
//        // valeurs pour this
//        sf::FloatRect   rect_this   = getBounds() ;
//
//        float gauche    = - rect_this.left  + cbl_gauche + ecart;
//        float milieu    = - (rect_this.left + rect_this.width/2 )   + cbl_milieu ;
//        float droite    = - (rect_this.left + rect_this.width  )    + cbl_droite  - ecart;
//
//        float haut      = - rect_this.top  + cbl_haut + ecart;
//        float centre    = - (rect_this.top + rect_this.height/2 )   + cbl_centre;
//        float bas       = - (rect_this.top + rect_this.height  )    + cbl_bas;
//
//
////
////        float gauche    = - rect_this.left  + ecart;
////        float milieu    = - (rect_this.left + rect_this.width/2 )   + this->fond->getSize().x/2 ;
////        float droite    = - (rect_this.left + rect_this.width  )    + this->fond->getSize().x  - ecart;
////
////        float haut      = - rect_this.top + ecart;
////        float centre    = - (rect_this.top + rect_this.height/2 )   + this->fond->getSize().y/2;
////        float bas       = - (rect_this.top + rect_this.height  )    + this->fond->getSize().y  - ecart;
//
//        switch ( newAlign ) {
//            case Alignements::Gau_Hau:{
//                setPosition( gauche , haut );
//            }break;
//
//            case Alignements::Mil_Hau:{
//                setPosition( milieu , haut );
//            }break;
//
//            case Alignements::Drt_Hau:{
//                setPosition( droite , haut );
//
//            }break;
//
//            case Alignements::Gau_Ctr:{
//                setPosition( gauche , centre );
//
//            }break;
//
//            case Alignements::Mil_Ctr:{
//                setPosition( milieu , centre );
//
//            }break;
//
//            case Alignements::Drt_Ctr:{
//                setPosition( droite , centre );
//
//            }break;
//
//            case Alignements::Gau_Bas:{
//                setPosition( gauche , bas );
//
//            }break;
//
//            case Alignements::Mil_Bas:{
//                setPosition( milieu , bas );
//
//            }break;
//
//            case Alignements::Drt_Bas:{
//                setPosition( droite , bas );
//
//            }break;
//
//            case Alignements::Libre:{
//
//            }break;
//
//            default:{}break;
//        }
//
//    }
}
