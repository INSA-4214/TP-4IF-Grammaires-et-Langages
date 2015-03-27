
#include "../Symbole.h"
#include "Etat41.h"
#include "Etat42.h"

Etat41::Etat41() : Etat() { }

bool Etat41::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::nb:
        automate->decalage(s, new Etat42());
           return true;
        default:
            return false;
}
return false;
}
