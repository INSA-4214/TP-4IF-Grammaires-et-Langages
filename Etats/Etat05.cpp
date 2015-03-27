
#include "../Symbole.h"
#include "Etat05.h"
#include "Etat12.h"

Etat05::Etat05() : Etat() { }

bool Etat05::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::pv:
        automate->decalage(s, new Etat12());
           return true;
        default:
            return false;
}
return false;
}
