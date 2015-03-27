
#include "../Symbole.h"
#include "Etat23.h"
#include "Etat33.h"

Etat23::Etat23() : Etat() { }

bool Etat23::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::nb);
    switch ( s->getIdent() ) {
        case Symbole::nb:
        automate->decalage(s, new Etat33());
           return true;

        default:
            return false;
}
return false;
}
