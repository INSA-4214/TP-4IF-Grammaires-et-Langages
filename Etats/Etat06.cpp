
#include "../Symbole.h"
#include "Etat06.h"
#include "Etat13.h"

Etat06::Etat06() : Etat() { }

bool Etat06::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
            automate->decalage(s, new Etat13());
           return true;
        default:
        automate->erreurSyntax("nom de variable attendu");
            return false;
}
return false;
}
