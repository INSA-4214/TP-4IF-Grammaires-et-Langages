/*
 * Automate.h
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#ifndef AUTOMATE_H_
#define AUTOMATE_H_

#include "Symbole.h"
#include "Programme.h"
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
	void erreurSyntax(std::string type);
	void erreurSyntax(std::string type, std::string strAtt);
	void erreurSyntax(std::string type, std::string strAtt, std::string strAtt2);
	std::stack<Etat*> *getPileEtats();
	std::stack<Symbole*> *getPileSymboles();
	void setAccepter(bool b);
	bool getAccepte();
	void print();
	void staticAnalysis();
	void exec();
	void transform();
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
	bool accepte;
	Lexer *lexer;

};

#endif /* AUTOMATE_H_ */
