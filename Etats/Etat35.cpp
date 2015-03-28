
#include "../Symbole.h"
#include "Etat35.h"
#include "Etat28.h"
#include "Etat29.h"

Etat35::Etat35() : Etat() { }

bool Etat35::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::E);
    switch ( s->getIdent() ) {
        case Symbole::Opa:
            automate->decalage(s, new Etat28());
           return true;
        case Symbole::Opm:
            automate->decalage(s, new Etat29());
            return true;
        case Symbole::multi:
        case Symbole::divi:
        case Symbole::plus:
        case Symbole::moins:
        case Symbole::FILEEND:
        case Symbole::pv :
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
