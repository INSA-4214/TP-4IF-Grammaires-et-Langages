#include "../Expr.h"
#include "../Symbole.h"
#include "Etat17.h"
#include <string>

Etat17::Etat17() : Etat() { }

bool Etat17::transition(Automate *automate, Symbole * s) {

    Nombre *symb = new Nombre();
    Symbole *nombre;
    std::string str_nombre;

    switch ( s->getIdent() ) {
        case Symbole::moins:
        case Symbole::plus :
        case Symbole::multi :
        case Symbole::divi :
        case Symbole::FILEEND :
        case Symbole::pv :
        case Symbole::parf :

        	// Reduction

        	nombre = automate->getPileSymboles()->top();
        	str_nombre = nombre->getStr();

        	symb->setValeur(atoi(str_nombre.c_str()));

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
