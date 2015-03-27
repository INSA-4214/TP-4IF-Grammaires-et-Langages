
#include "../Symbole.h"
#include "Etat34.h"
#include "Etat26.h"
#include "Etat27.h"
#include "Etat28.h"
#include "Etat29.h"

Etat34::Etat34() : Etat() { }

bool Etat34::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::E);
    switch ( s->getIdent() ) {
        case Symbole::multi:
        automate->decalage(s, new Etat26());
           return true;
        case Symbole::divi:
          automate->decalage(s, new Etat27());
            return true;
        case Symbole::Opa:
            automate->decalage(s, new Etat28());
           return true;
        case Symbole::Opm:
            automate->decalage(s, new Etat29());
            return true;
        case Symbole::plus:
        case Symbole::moins:
        case Symbole::FILEEND:
         for ( int i = 0 ; i < 3 ; i++ ) {
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
            }
           if (!automate->getPileEtats()->top()->transition(automate, &symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
            return false;
}
return false;
}
