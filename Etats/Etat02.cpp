
#include "../Symbole.h"
#include "Etat02.h"

Etat02::Etat02() : Etat() { }

bool Etat02::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
  /*  switch ( s->getIdent() ) {
        case Symbole::I:
            automaton->decalage(t, new E2());
            return true;
            if (!automaton->getStackStates()->top()->transition(
            automaton, &symb)) return false;
            if (!automaton->getStackStates()->top()->transition(
            automaton, t)) return false;
            return true;
        default:
            return false;
    }*/
    return false;
}
