
#include "../Symbole.h"
#include "Etat21.h"
#include "Etat17.h"
#include "Etat18.h"
#include "Etat20.h"
#include "Etat31.h"

Etat21::Etat21() : Etat() { }

bool Etat21::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::E);
    switch ( s->getIdent() ) {
        case Symbole::E:
        automate->decalage(s, new Etat31());
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
