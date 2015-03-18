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

	Transition();
	virtual ~Transition();
};

#endif /* TRANSITION_H_ */
