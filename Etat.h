/*
 * Etat.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef ETAT_H_
#define ETAT_H_

#include <boost/algorithm/string.hpp>
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

class Etat0: public Etat {
public:


};

class Etat1: public Etat {
public:


};

class Etat2: public Etat {
public:


};

class Etat3: public Etat {
public:


};

class Etat4: public Etat {
public:


};

class Etat5: public Etat {
public:


};

#endif /* ETAT_H_ */
