/*
 * Programme.h
 *
 *  Created on: 28 mars 2015
 *      Author: Huber
 */

#ifndef PROGRAMME_H_
#define PROGRAMME_H_

#include "BlocInstruction.h"
#include "BlocDeclaration.h"

class Programme: public Symbole {
public:

	Programme()
		:Symbole(Symbole::P), blocI(new BlocInstruction()), blocD(new BlocDeclaration()){}

	Programme(BlocInstruction *unBlocI, BlocDeclaration *unBlocD)
		:Symbole(Symbole::P), blocI(unBlocI), blocD(unBlocD){}

	virtual ~Programme();

protected:
	BlocInstruction* blocI;
	BlocDeclaration* blocD;
};

#endif /* PROGRAMME_H_ */
