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
#include <deque>

class Automate {

public:
	Automate();
	virtual ~Automate();
	void lecture();

private:

	std::deque<Etat> etats;
	std::deque<Symbole> symboles;

};

#endif /* AUTOMATE_H_ */
