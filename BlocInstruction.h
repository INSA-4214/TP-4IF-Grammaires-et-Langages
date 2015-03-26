/*
 * BlocInstruction.h
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#ifndef BLOCINSTRUCTION_H_
#define BLOCINSTRUCTION_H_

#include "Instruction.h"
#include "Symbole.h"
#include <set>

class BlocDeclaration: public Symbole {
public:

	BlocDeclaration()
		:Symbole(Symbole::Bi), instructions(std::set<Instruction*>()){}

	BlocDeclaration(std::set<Instruction*> lesDeclarations)
		:Symbole(Symbole::Bi), instructions(lesDeclarations){}

	virtual ~BlocDeclaration(){}

protected:

	std::set<Instruction*> instructions;
};


#endif /* BLOCINSTRUCTION_H_ */
