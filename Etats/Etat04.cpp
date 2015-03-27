
#include "../Symbole.h"
#include "Etat04.h"
#include "Etat11.h"
#include "Etat10.h"
#include "Etat08.h"
#include "Etat09.h"

Etat04::Etat04() : Etat() { }

bool Etat04::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat11());
           return true;
        case Symbole::w:
          automate->decalage(s, new Etat10());
            return true;
        case Symbole::r:
            automate->decalage(s, new Etat08());
            return true;
        case Symbole::I:
            automate->decalage(s, new Etat09());
            return true;
        default:
            return false;
}
return false;
}