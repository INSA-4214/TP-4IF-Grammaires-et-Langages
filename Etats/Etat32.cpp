
#include "../Symbole.h"
#include "Etat32.h"
#include "Etat37.h"

Etat32::Etat32() : Etat() { }

bool Etat32::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat37());
           return true;

        default:
        automate->erreurSyntax("nom de variable attendu");
            return false;
}
return false;
}
