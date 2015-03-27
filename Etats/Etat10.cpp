
#include "../Symbole.h"
#include "Etat10.h"
#include "Etat18.h"
#include "Etat17.h"
#include "Etat19.h"
#include "Etat20.h"

Etat10::Etat10() : Etat() { }

bool Etat10::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat18());
           return true;
           case Symbole::nb:
        automate->decalage(s, new Etat17());
           return true;
           case Symbole::paro:
        automate->decalage(s, new Etat20());
           return true;
           case Symbole::E:
        automate->decalage(s, new Etat19());
           return true;
        default:
            return false;
}
return false;
}
