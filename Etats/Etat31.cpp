#include "../Affectation.h"
#include "../Symbole.h"
#include "Etat31.h"
#include "Etat26.h"
#include "Etat27.h"
#include "Etat24.h"
#include "Etat25.h"
#include "Etat28.h"
#include "Etat29.h"

Etat31::Etat31() : Etat() { }

bool Etat31::transition(Automate *automate, Symbole * s) {

    Affectation *symb = new Affectation();
    Expr *e;
    Symbole *idVar;

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
        case Symbole::Opa:
            automate->decalage(s, new Etat28());
           return true;
        case Symbole::Opm:
            automate->decalage(s, new Etat29());
            return true;
        case Symbole::pv:
        case Symbole::FILEEND:

        // Reduction

			e = (Expr*) automate->getPileSymboles()->top();
			symb -> setExpr(e);

			automate->getPileSymboles()->pop();
			automate->getPileSymboles()->pop();

			idVar = automate->getPileSymboles()->top();
			symb -> setIdVar(idVar->getStr());

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
