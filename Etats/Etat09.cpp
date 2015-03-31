
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
        automate->decalage(new Symbole(Symbole::pv), new Etat16());
        automate->erreurSyntax("symbole", ";");
            return false;
}
return false;
}
