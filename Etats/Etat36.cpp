
#include "../Symbole.h"
#include "Etat36.h"


Etat36::Etat36() : Etat() { }

bool Etat36::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::E);
    switch ( s->getIdent() ) {
        case Symbole::multi:
        case Symbole::divi:
        case Symbole::plus:
        case Symbole::moins:
        case Symbole::FILEEND:
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
