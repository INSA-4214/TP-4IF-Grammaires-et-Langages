
#include "../Symbole.h"
#include "Etat39.h"
#include "Etat40.h"

Etat39::Etat39() : Etat() { }

bool Etat39::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat40());
           return true;
        default:
            return false;
}
return false;
}
