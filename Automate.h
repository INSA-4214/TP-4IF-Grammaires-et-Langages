/*
 * Automate.h
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#ifndef AUTOMATE_H_
#define AUTOMATE_H_

#include "Symbole.h"
#include "Etat.h"
#include "Lexer.h"
#include "Transition.h"
#include <stack>
#include <string>
class Automate {

public:
	Automate(Lexer *lexer);
	bool lecture();
	void decalage(Symbole *s,Etat *e);
	std::stack<Etat*> *getPileEtats();
	std::stack<Symbole*> *getPileSymboles();
	void setAccepter(bool b);
	virtual ~Automate();

protected:

/*La classe automate est dÃ©fini par :
-une pile d'etats
-une pile de symbole (token)
-un analyseur lexical (lexer)
-un etat d'avancement (valider/refuser l'analyse)
*/

	std::stack<Etat*> pileEtats;
	std::stack<Symbole*> pileSymboles;
	std::map<std::string, Symbole*> mapConst; // Symbole D
	std::map<std::string, Symbole*> mapVar; // Symbole D
	bool accepte;
	Lexer *lexer;

};

#endif /* AUTOMATE_H_ */
