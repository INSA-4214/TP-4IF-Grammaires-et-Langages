/*
 * Etat1.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef ETAT1_H_
#define ETAT1_H_
#include "Etat.h"

class Etat1 : public Etat {
public:
	Etat1(std::string name):
		Etat(name){}
	Etat1():
		Etat(""){}
	virtual ~Etat1();
	bool transition(Automate & automate, Symbole *s);

};

#endif /* ETAT1_H_ */
