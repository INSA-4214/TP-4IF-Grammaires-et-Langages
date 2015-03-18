/*
 * Transition.cpp
 *
 *  Created on: 18 mars 2015
 *      Author: Vincent
 */

#include "Transition.h"

Transition::Transition() {
	// TODO Auto-generated constructor stub

}

Transition::~Transition() {}

void DeplacerTrans::doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats){

PileEtats->push(cible);
}

void ReduireTrans::doTransition(Transition::TableTransition & tableTrans, std::stack<Etat> * PileEtats){

	for(int i=0;i < depile; i++){

		PileEtats->pop();

		tableTrans.find(PileEtats->top())->second.find(precedent)->second->doTransition(tableTrans, PileEtats);
	}

}

