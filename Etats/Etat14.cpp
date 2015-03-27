
#include "../Symbole.h"
#include "Etat14.h"
#include "Etat23.h"

Etat14::Etat14() : Etat() { }

bool Etat14::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::aff:
        automate->decalage(s, new Etat23());
           return true;
        default:
            return false;
}
return false;
}
