
#include "../Symbole.h"
#include "Etat11.h"
#include "Etat21.h"

Etat11::Etat11() : Etat() { }

bool Etat11::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::aff:
        automate->decalage(s, new Etat21());
           return true;
        default:
        automate->decalage(new Symbole(Symbole::aff), new Etat21());
        automate->erreurSyntax("operateur", ":=");
            return false;
}
return false;
}
