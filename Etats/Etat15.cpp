
#include "../Symbole.h"
#include "Etat15.h"

Etat15::Etat15() : Etat() { }

bool Etat15::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::I);
    switch ( s->getIdent() ) {
        case Symbole::pv:
        case Symbole::FILEEND :
// Reduction I depile 2
           for ( int i = 0 ; i < 2 ; i++ ) {
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
