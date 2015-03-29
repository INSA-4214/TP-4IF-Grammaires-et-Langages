#include "../Expr.h"
#include "../Symbole.h"
#include "Etat36.h"


Etat36::Etat36() : Etat() { }

bool Etat36::transition(Automate *automate, Symbole * s) {

	Expr *symb;

    switch ( s->getIdent() ) {
        case Symbole::multi:
        case Symbole::divi:
        case Symbole::plus:
        case Symbole::moins:
        case Symbole::FILEEND:
        case Symbole::pv :

        	// Reduction
        	automate->getPileSymboles()->pop();

        	symb = (Expr*) automate->getPileSymboles()->top();

        	automate->getPileSymboles()->pop();
        	automate->getPileSymboles()->pop();

            for ( int i = 0 ; i < 3 ; i++ ) {
               automate->getPileEtats()->pop();
            }
           if (!automate->getPileEtats()->top()->transition(automate, symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
            return false;
}
return false;
}
