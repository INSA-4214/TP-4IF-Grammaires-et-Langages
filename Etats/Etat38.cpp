#include "../Symbole.h"
#include "../Declaration.h"
#include "../Expr.h"
#include "Etat38.h"
#include "Etat39.h"


Etat38::Etat38() : Etat() { }

bool Etat38::transition(Automate *automate, Symbole * s) {

	DCst *symb = new DCst();
    Lc *lc;
    Nombre *nb;
    std::string id;

    switch ( s->getIdent() ) {
        case Symbole::virg :
        automate->decalage(s, new Etat39());
           return true;
        case Symbole::pv:
        case Symbole::FILEEND :

			// Reduction

        	// On set les paires du DCst
        	lc = (Lc*) automate->getPileSymboles()->top();
        	symb->setPairsConst(lc->getPairsconst());

        	automate->getPileSymboles()->pop();

        	nb = (Nombre*) automate->getPileSymboles()->top();

        	automate->getPileSymboles()->pop();
        	automate->getPileSymboles()->pop();

        	id = automate->getPileSymboles()->top()->getStr();

        	// On ajoute la nouvelle paire
        	symb->addidcons(id, nb->getValeur());

        	automate->getPileSymboles()->pop();
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
