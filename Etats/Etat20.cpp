
#include "../Symbole.h"
#include "Etat20.h"
#include "Etat30.h"

Etat20::Etat20() : Etat() { }

bool Etat20::transition(Automate *automate, Symbole * s) {

    Symbole symb = Symbole(Symbole::E);

    switch ( s->getIdent() ) {
        case Symbole::E:
        automate->decalage(s, new Etat30());
           return true;
        default:
            return false;
}
return false;
}
