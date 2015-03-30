
#include "../Symbole.h"
#include "Etat30.h"
#include "Etat26.h"
#include "Etat27.h"
#include "Etat24.h"
#include "Etat25.h"
#include "Etat36.h"
#include "Etat28.h"
#include "Etat29.h"

Etat30::Etat30() : Etat() { }

bool Etat30::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::multi:
        automate->decalage(s, new Etat26());
           return true;
        case Symbole::divi:
          automate->decalage(s, new Etat27());
            return true;
        case Symbole::plus:
            automate->decalage(s, new Etat24());
           return true;
        case Symbole::moins:
            automate->decalage(s, new Etat25());
            return true;
            case Symbole::parf:
          automate->decalage(s, new Etat36());
            return true;
        case Symbole::Opa:
            automate->decalage(s, new Etat28());
           return true;
        case Symbole::Opm:
            automate->decalage(s, new Etat29());
            return true;
        default:
        automate->erreurSyntax("operateur de calcul ou ')' attendu");
            return false;
}
return false;
}
