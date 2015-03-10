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
#include <boost/lockfree/stack.hpp>

class Automate {

public:
	Automate();
	virtual ~Automate();
	void lecture();

private:

	boost::lockfree::stack<Etat> etats;
	boost::lockfree::stack<Symbole> symboles;

};

#endif /* AUTOMATE_H_ */
