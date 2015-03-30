
#include "../Symbole.h"
#include "Etat07.h"
#include "Etat14.h"

Etat07::Etat07() : Etat() { }

bool Etat07::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat14());
           return true;
        default:
        automate->erreurSyntax("nom de variable attendu");
            return false;
}
return false;
}
