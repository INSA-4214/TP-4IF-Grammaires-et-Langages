/*
 * Transition.cpp
 *
 *  Created on: 18 mars 2015
 *      Author: Vincent
 */

#include "Transition.h"

Transition::~Transition() {}

bool DeplacerTrans::doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats){

	PileEtats->push(cible);
	return false;
}

bool ReduireTrans::doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats){

	for(int i=0;i < depile; i++){

		PileEtats->pop();
	}
		return false;
}

bool AcceptTrans::doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats){

	return true;

}
