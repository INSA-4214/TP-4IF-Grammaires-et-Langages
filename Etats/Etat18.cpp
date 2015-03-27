
#include "../Symbole.h"
#include "Etat18.h"

Etat18::Etat18() : Etat() { }

bool Etat18::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::E);
    switch ( s->getIdent() ) {
        case Symbole::moins:
        case Symbole::plus :
        case Symbole::multi :
        case Symbole::divi :
        case Symbole::FILEEND :
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
