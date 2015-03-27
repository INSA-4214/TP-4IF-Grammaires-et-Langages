#include "../Symbole.h"
#include "Etat42.h"

Etat42::Etat42() : Etat() { }

bool Etat42::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Lv);
    switch ( s->getIdent() ) {
        case Symbole::pv:
        case Symbole::virg :
        case Symbole::FILEEND :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
            for ( int i = 0 ; i < 5 ; i++ ) {
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
