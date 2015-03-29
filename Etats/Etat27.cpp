#include "../Operateur.h"
#include "../Symbole.h"
#include "Etat27.h"

Etat27::Etat27() : Etat() { }

bool Etat27::transition(Automate *automate, Symbole * s) {

    OpeMult *symb = new OpeMult(Symbole::divi);

    switch ( s->getIdent() ) {
            case Symbole::idvar:
            case Symbole::nb:
            case Symbole::FILEEND:
            case Symbole::paro:

            	// Reduction
				for ( int i = 0 ; i < 1 ; i++ ) {
				   automate->getPileSymboles()->pop();
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
