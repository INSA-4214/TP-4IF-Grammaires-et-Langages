
#include "../Symbole.h"
#include "Etat09.h"
#include "Etat16.h"

Etat09::Etat09() : Etat() { }

bool Etat09::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::pv:
        automate->decalage(s, new Etat16());
           return true;
        default:
            return false;
}
return false;
}
