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

class BlocInstruction: public Symbole {
public:

	BlocInstruction()
		:Symbole(Symbole::Bi), instructions(std::set<Instruction*>()){}

	BlocInstruction(std::set<Instruction*> lesDeclarations)
		:Symbole(Symbole::Bi), instructions(lesDeclarations){}

	void addInstruction(Instruction* uneInstruction) {
		instructions.insert(uneInstruction);
	}

	void print();
	void exec();
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
	virtual ~BlocInstruction(){}

protected:

	std::set<Instruction*> instructions;
};


#endif /* BLOCINSTRUCTION_H_ */
