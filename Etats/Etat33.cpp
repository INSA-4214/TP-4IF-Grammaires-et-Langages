#include "../Symbole.h"
#include "../Declaration.h"
#include "Etat33.h"
#include "Etat38.h"

#include <stdio.h>
using namespace std;
Etat33::Etat33() : Etat() { }

bool Etat33::transition(Automate *automate, Symbole * s) {
    Lc* symb = new Lc();
    switch ( s->getIdent() ) {
        case Symbole::Lc:
        automate->decalage(s, new Etat38());
           return true;
        case Symbole::pv :
        case Symbole::virg :
        case Symbole::FILEEND :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
           if (!automate->getPileEtats()->top()->transition(automate, symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
        automate->erreurSyntax("symbole", ",", ";");
            return false;
}
return false;
}
