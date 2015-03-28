#include "../Symbole.h"
#include "../Declaration.h"
#include "Etat37.h"
#include <set>
Etat37::Etat37() : Etat() { }

bool Etat37::transition(Automate *automate, Symbole * s) {
   Symbole* lastidvar = automate->getPileSymboles()->top();
   Lv* symb = new Lv();
    switch ( s->getIdent() ) {
       case Symbole::pv:
       case Symbole::virg :
       case Symbole::FILEEND :

           // Reduction R�gle 13 - 0 Level On pop Bd car Bd->.
           for ( int i = 0 ; i < 2 ; i++ ) {
              automate->getPileSymboles()->pop();
              automate->getPileEtats()->pop();
           }

           //On caste le top de la pile en Lv

           //On construit le symbole � partir des infos contenues dans le Lv
           symb->Lv::setSetidvar(((Lv*) automate->getPileSymboles()->top())->getSetidvar());

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
