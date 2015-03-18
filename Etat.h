/*
 * Etat.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef ETAT_H_
#define ETAT_H_

#include <string>
#include "Symbole.h"
class Automate;

class Etat {
public:
	Etat():
		name(""){}
	Etat(std::string name);
	virtual ~Etat();
	void print() const;
	virtual bool transition(Automate & automate, Symbole *s) = 0;

protected:
	std::string name;
};

#endif /* ETAT_H_ */
