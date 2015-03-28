
#include "../Symbole.h"
#include "Etat03.h"

Etat03::Etat03() : Etat() { }

bool Etat03::transition(Automate *automate, Symbole * s) {
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
