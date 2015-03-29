#include "../Expr.h"
#include "../Symbole.h"
#include "Etat18.h"

Etat18::Etat18() : Etat() { }

bool Etat18::transition(Automate *automate, Symbole * s) {

    Variable *symb = new Variable();
    Symbole *idVariable;

    switch ( s->getIdent() ) {
        case Symbole::moins:
        case Symbole::plus :
        case Symbole::multi :
        case Symbole::divi :
        case Symbole::FILEEND :
        case Symbole::pv :

           //Reduction

        	idVariable = automate->getPileSymboles()->top();
        	symb -> setNom(idVariable->getStr());

        	automate->getPileSymboles()->pop();
            automate->getPileEtats()->pop();

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
