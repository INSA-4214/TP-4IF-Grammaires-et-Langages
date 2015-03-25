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
#include "Transition.h"
#include <stack>

class Automate {

public:
	Automate();
	virtual ~Automate();
	void lecture();

private:

	std::stack<Etat> etats;
	std::stack<Symbole> symboles;
	Transition::TableTransition transitions;

};

#endif /* AUTOMATE_H_ */
