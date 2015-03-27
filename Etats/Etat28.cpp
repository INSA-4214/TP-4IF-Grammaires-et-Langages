
#include "../Symbole.h"
#include "Etat28.h"
#include "Etat17.h"
#include "Etat18.h"
#include "Etat20.h"
#include "Etat34.h"

Etat28::Etat28() : Etat() { }

bool Etat28::transition(Automate *automate, Symbole * s) {
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
            automate->decalage(s, new Etat34());
            return true;
        default:
            return false;
}
return false;
}
