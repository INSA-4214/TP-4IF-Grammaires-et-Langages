#include "../Expr.h"
#include "../Operateur.h"
#include "../Symbole.h"
#include "Etat35.h"
#include "Etat28.h"
#include "Etat29.h"

Etat35::Etat35() : Etat() { }

bool Etat35::transition(Automate *automate, Symbole * s) {

	MultExpr *symb = new MultExpr();
	Expr *droite;
	Expr *gauche;
	Operateur *ope;

	switch ( s->getIdent() ) {
        case Symbole::Opa:
            automate->decalage(s, new Etat28());
           return true;
        case Symbole::Opm:
            automate->decalage(s, new Etat29());
            return true;
        case Symbole::multi:
        case Symbole::divi:
        case Symbole::plus:
        case Symbole::moins:
        case Symbole::FILEEND:
        case Symbole::pv :
        case Symbole::parf :

        	// Reduction

			droite = (Expr*) automate->getPileSymboles()->top();
			symb->setDroite(droite);

			automate->getPileSymboles()->pop();

			ope = (Operateur*) automate->getPileSymboles()->top();
			symb->setOperateur(ope);

			automate->getPileSymboles()->pop();

			gauche = (Expr*) automate->getPileSymboles()->top();
			symb->setGauche(gauche);

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
        automate->erreurSyntax("operateur de calcul attendu");
            return false;
}
return false;
}
