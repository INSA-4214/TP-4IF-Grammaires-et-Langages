#include "../Symbole.h"
#include "../Declaration.h"
#include "../Expr.h"

#include "Etat42.h"

Etat42::Etat42() : Etat() { }

bool Etat42::transition(Automate *automate, Symbole * s) {

    Lc *symb;
    Nombre* nb;
    std::string id;

    switch ( s->getIdent() ) {
        case Symbole::pv:
        case Symbole::virg :
        case Symbole::FILEEND :

        	// Reduction

        	nb = (Nombre*) automate->getPileSymboles()->top();

        	automate->getPileSymboles()->pop();
        	automate->getPileSymboles()->pop();

        	id = automate->getPileSymboles()->top()->getStr();

        	automate->getPileSymboles()->pop();
        	automate->getPileSymboles()->pop();

        	symb = (Lc*) automate->getPileSymboles()->top();
        	symb->addidcons(id, nb->getValeur());

        	automate->getPileSymboles()->pop();

            for ( int i = 0 ; i < 5 ; i++ ) {
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
