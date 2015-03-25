
#include "../Symbole.h"
#include "Etat01.h"

Etat01::Etat01() : Etat() { }

bool Etat01::transition(Automate *automate, Symbole * s) {
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
