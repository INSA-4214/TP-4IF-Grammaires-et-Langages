#include "../BlocDeclaration.h"
#include "../Declaration.h"
#include "../Symbole.h"
#include "Etat12.h"

Etat12::Etat12() : Etat() { }

bool Etat12::transition(Automate *automate, Symbole * s) {

    BlocDeclaration *symb;
    DVar *Dv;
    DCst *Dc;

    switch ( s->getIdent() ) {

        case Symbole::var :
        case Symbole::cst :
        case Symbole::idvar :
        case Symbole::w :
        case Symbole::r :
        case Symbole::FILEEND :

		   // Reduction Règle 12 - Bd->Bd D pv
		   for ( int i = 0 ; i < 3 ; i++ ) {
			   automate->getPileEtats()->pop();
		   }

		   automate->getPileSymboles()->pop();

		   Dv = dynamic_cast <DVar*> (automate->getPileSymboles()->top());
		   Dc = dynamic_cast <DCst*> (automate->getPileSymboles()->top());

		   automate->getPileSymboles()->pop();

		   symb = (BlocDeclaration*) automate->getPileSymboles()->top();

		   if (Dv){
			   symb->addVar(Dv);
		   }

		   if (Dc){
			   symb->addConst(Dc);
		   }

		   automate->getPileSymboles()->pop();

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
