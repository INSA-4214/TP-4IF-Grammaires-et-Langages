
#include "../Symbole.h"
#include "Etat22.h"
#include "Etat32.h"
#include "../Declaration.h"
#include <set>

#include <stdio.h>

using namespace std;

Etat22::Etat22() : Etat() { }

bool Etat22::transition(Automate *automate, Symbole * s) {

    DVar* symb = new DVar();
   Symbole* lastidvar = automate->getPileSymboles()->top();

   DVar* top = (DVar*) automate->getPileSymboles()->top();

           //On construit le symbole à partir des infos contenues dans le Lv
           symb->DVar::setSetidvar(top->getSetidvar());


    switch ( s->getIdent() ) {
        case Symbole::virg:
        automate->decalage(s, new Etat32());
           return true;
        case Symbole::pv:
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.


           //On construit le symbole à partir des infos contenues dans le Dvar


               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();

               lastidvar = automate->getPileSymboles()->top();
                symb->addidvar(lastidvar);
            for ( int i = 0 ; i < 2 ; i++ ) {
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
            }


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
