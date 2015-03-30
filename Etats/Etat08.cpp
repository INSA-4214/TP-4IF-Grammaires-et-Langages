
#include "../Symbole.h"
#include "Etat08.h"
#include "Etat15.h"

Etat08::Etat08() : Etat() { }

bool Etat08::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat15());
           return true;
        default:
        automate->erreurSyntax("nom de variable attendu");
            return false;
}
return false;
}
