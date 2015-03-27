
#include "../Symbole.h"
#include "Etat00.h"
#include "Etat01.h"
#include "Etat02.h"

Etat00::Etat00() : Etat() { }

bool Etat00::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::P:
        automate->decalage(s, new Etat01());
           return true;
        case Symbole::Bd:
          automate->decalage(s, new Etat02());
            return true;
        case Symbole::var:
        case Symbole::cst :
        case Symbole::w :
        case Symbole::r :
        case Symbole::FILEEND :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
           if (!automate->getPileEtats()->top()->transition(automate, &symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
            return false;
}
return false;
}
