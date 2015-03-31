
#include "../Symbole.h"
#include "../Declaration.h"
#include "Etat13.h"
#include "Etat22.h"
#include <set>
Etat13::Etat13() : Etat() { }

bool Etat13::transition(Automate *automate, Symbole * s) {
   Lv* symb = new Lv();
    switch ( s->getIdent() ) {
        case Symbole::Lv:
        automate->decalage(s, new Etat22());
           return true;
        case Symbole::pv:
        case Symbole::virg :
        case Symbole::FILEEND :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
           if (!automate->getPileEtats()->top()->transition(automate, symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
        automate->decalage(symb, new Etat22());
        automate->erreurSyntax("symbole", ",");
            return false;
}
return false;
}
