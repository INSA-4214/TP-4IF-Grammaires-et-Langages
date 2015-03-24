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
	 typedef static const std::map<Etat::EtatId, std::map<Symbole::Id, Transition*> > TableTransition;

	 virtual bool doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats) = 0;
	 virtual ~Transition();
};

class DeplacerTrans: public Transition {
public:

	DeplacerTrans(Etat uneCible): cible(uneCible){}

	bool doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats);

protected:
	Etat cible;


};

class ReduireTrans: public Transition{
public:

	ReduireTrans(int depile):depile(depile){}

	bool doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats);

protected:
	int depile;
	Symbole::Id precedent;
};

class AcceptTrans: public Transition{
public:

	AcceptTrans();
	bool doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats);
};
#endif /* TRANSITION_H_ */
