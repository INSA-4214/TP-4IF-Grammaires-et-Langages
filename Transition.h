/*
 * Transition.h
 *
 *  Created on: 18 mars 2015
 *      Author: Vincent
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

#include <map>
#include <stack>
#include "Symbole.h"
#include "Etat.h"


class Transition {
public:
	 typedef std::map<Etat::Id, std::map<Symbole::ident, Transition *>> TableTransition;

	 virtual void doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats) = 0;
	virtual ~Transition();
};

class DeplacerTrans: public Transition {
public:

	DeplacerTrans(Etat::Etat uneCible): cible(cible){}

	void doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats);

protected:
	Etat::Etat cible;


};

class ReduireTrans: public Transition{
public:

	ReduireTrans(int depile):depile(depile){}

	void doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats);

protected:
	int depile;
	Symbole::ident precedent;
};
#endif /* TRANSITION_H_ */
