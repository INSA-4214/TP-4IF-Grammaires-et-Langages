
#include "../Symbole.h"
#include "Etat22.h"
#include "Etat32.h"

Etat22::Etat22() : Etat() { }

bool Etat22::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::D);
    switch ( s->getIdent() ) {
        case Symbole::virg:
        automate->decalage(s, new Etat32());
           return true;
        case Symbole::pv:
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
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
