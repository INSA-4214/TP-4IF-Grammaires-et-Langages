
#include "../Symbole.h"
#include "Etat12.h"

Etat12::Etat12() : Etat() { }

bool Etat12::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {

        case Symbole::var:
        case Symbole::cst :
        case Symbole::idvar :
        case Symbole::w :
        case Symbole::r :
        case Symbole::FILEEND :
// Reduction Règle 12 - Bd->Bd D pv
           for ( int i = 0 ; i < 3 ; i++ ) {
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
            }
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
