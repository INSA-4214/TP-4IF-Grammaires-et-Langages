
#include "../Symbole.h"
#include "Etat40.h"
#include "Etat41.h"

Etat40::Etat40() : Etat() { }

bool Etat40::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::egal:
        automate->decalage(s, new Etat41());
           return true;
        default:
        automate->erreurSyntax("operateur", ":=");
            return false;
}
return false;
}
