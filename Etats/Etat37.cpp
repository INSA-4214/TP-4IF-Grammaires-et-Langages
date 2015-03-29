#include "../Symbole.h"
#include "../Declaration.h"
#include "Etat37.h"
#include <set>
Etat37::Etat37() : Etat() { }

bool Etat37::transition(Automate *automate, Symbole * s) {

   std::string lastidvar;
   Lv* symb;

    switch ( s->getIdent() ) {
       case Symbole::pv:
       case Symbole::virg :
       case Symbole::FILEEND :

           // Reduction

    	   lastidvar = automate->getPileSymboles()->top()->getStr();

           for ( int i = 0 ; i < 2 ; i++ ) {
              automate->getPileSymboles()->pop();
              automate->getPileEtats()->pop();
           }

           symb = (Lv*) automate->getPileSymboles()->top();

           // On ajoute le dernier idvar
           symb->addidvar(lastidvar);

           automate->getPileSymboles()->pop();
           automate->getPileEtats()->pop();

          if (!automate->getPileEtats()->top()->transition(automate, symb))
               return false;
          if (!automate->getPileEtats()->top()->transition(automate, s))
               return false;
          return true;
       default:
           return false;
}
return false;
}
