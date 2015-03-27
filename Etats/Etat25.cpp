
#include "../Symbole.h"
#include "Etat25.h"

Etat25::Etat25() : Etat() { }

bool Etat25::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Opa);
    switch ( s->getIdent() ) {
            case Symbole::idvar:
            case Symbole::nb:
            case Symbole::FILEEND:
            case Symbole::paro:
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
            for ( int i = 0 ; i < 1 ; i++ ) {
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
