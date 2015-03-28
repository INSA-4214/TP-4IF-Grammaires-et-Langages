/*
 * Declaration.h
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#ifndef DECLARATION_H_
#define DECLARATION_H_
#include "Symbole.h"

class DVar: public Symbole{

public:

	DVar(Symbole::Id id): Symbole(id){}
};

class DCst: public Symbole{

public:

	DCst(Symbole::Id id, int val) : Symbole(id), valeur(val){}

protected:

	int valeur;
};

#endif /* DECLARATION_H_ */
