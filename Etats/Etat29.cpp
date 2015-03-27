
#include "../Symbole.h"
#include "Etat29.h"
#include "Etat17.h"
#include "Etat18.h"
#include "Etat20.h"
#include "Etat35.h"

Etat29::Etat29() : Etat() { }

bool Etat29::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::nb:
        automate->decalage(s, new Etat17());
           return true;
        case Symbole::idvar:
          automate->decalage(s, new Etat18());
            return true;
        case Symbole::paro:
            automate->decalage(s, new Etat20());
           return true;
        case Symbole::E:
            automate->decalage(s, new Etat35());
            return true;
        default:
            return false;
}
return false;
}
