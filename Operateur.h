/*
 * Operateur.h
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#ifndef OPERATEUR_H_
#define OPERATEUR_H_
#include "Symbole.h"

class Operateur: public Symbole {
public:
	Operateur(Symbole::Id id)
		:Symbole(id){}
	virtual ~Operateur();
};

class OpeMult: public Operateur {
public:
	OpeMult(Symbole::Id id)
		:Operateur(id){}

};

class OpePlus: public Operateur {

public:
	OpePlus(Symbole::Id id)
		: Operateur(id){}

};

class OuvrePar: public Operateur {
public:
	OuvrePar(Symbole::Id id) : Operateur(id){}

};

class FermePar: public Operateur {
public:
	FermePar(Symbole::Id id) : Operateur(id){}

};


class Virg: public Operateur {
public:
	Virg(Symbole::Id id) : Operateur(id){}

};

class Pv: public Operateur {
public:
	Pv(Symbole::Id id) : Operateur(id){}

};


#endif /* OPERATEUR_H_ */
