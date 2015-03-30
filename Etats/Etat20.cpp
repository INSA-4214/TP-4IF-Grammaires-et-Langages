
#include "../Symbole.h"
#include "Etat20.h"
#include "Etat30.h"
#include "Etat18.h"
#include "Etat17.h"

Etat20::Etat20() : Etat() { }

bool Etat20::transition(Automate *automate, Symbole * s) {

    Symbole symb = Symbole(Symbole::E);

    switch ( s->getIdent() ) {
        case Symbole::E:
        automate->decalage(s, new Etat30());
           return true;
        case Symbole::idvar:
                automate->decalage(s, new Etat18());
                   return true;
        case Symbole::nb:
                automate->decalage(s, new Etat17());
                   return true;
        case Symbole::paro:
                automate->decalage(s, new Etat20());
                   return true;
        default:
            return false;
}
return false;
}
