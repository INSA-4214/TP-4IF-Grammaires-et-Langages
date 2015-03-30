
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
    std::string lastidvar;
    Lv* lv;

    switch ( s->getIdent() ) {
        case Symbole::virg:
        automate->decalage(s, new Etat32());
           return true;
        case Symbole::pv:

        	// Reduction
            lv = (Lv*) automate->getPileSymboles()->top();

            automate->getPileSymboles()->pop();

            lastidvar = automate->getPileSymboles()->top()->getStr();

            automate->getPileSymboles()->pop();
            automate->getPileSymboles()->pop();

            //On construit le symbole à partir des infos contenues dans le Dvar
            symb->setIdvars(lv->getSetidvar());
			symb->addidvar(lastidvar);

            for ( int i = 0 ; i < 3 ; i++ ) {
               automate->getPileEtats()->pop();
            }

           if (!automate->getPileEtats()->top()->transition(automate, symb)) {
               return false;
           }

           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;

           return true;
        default:
        automate->erreurSyntax("symbole", ",", ";");
            return false;
}
return false;
}
