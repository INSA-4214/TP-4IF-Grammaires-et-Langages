#include "../Operateur.h"
#include "../Symbole.h"
#include "Etat24.h"

Etat24::Etat24() : Etat() { }

bool Etat24::transition(Automate *automate, Symbole * s) {

    OpePlus *symb = new OpePlus(Symbole::plus);

    switch ( s->getIdent() ) {
            case Symbole::idvar:
            case Symbole::nb:
            case Symbole::FILEEND:
            case Symbole::paro:

			   // Reduction
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
