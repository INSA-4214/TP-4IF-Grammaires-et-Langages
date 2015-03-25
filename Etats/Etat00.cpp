
#include "../Symbole.h"
#include "Etat00.h"

Etat00::Etat00() : Etat() { }

bool Etat00::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::P:
         //  automate->decalage(s, new Etat01());
           return true;
        case Symbole::Bd:
        //   automate->decalage(s, new Etat02());
            return true;
        case Symbole::idvar:
        case Symbole::cst :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
       //     if (!automaton->getStackStates()->top()->transition(
         //   automaton, &token)) return false;
           // if (!automaton->getStackStates()->top()->transition(
           // automaton, t)) return false;
            return true;
        default:
            return false;
}
return false;
}
