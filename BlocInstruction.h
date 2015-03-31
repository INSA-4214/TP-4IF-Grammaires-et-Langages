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
#include <vector>

class BlocInstruction: public Symbole {
public:

	BlocInstruction()
		:Symbole(Symbole::Bi), instructions(std::vector<Instruction*>()){}

	BlocInstruction(std::vector<Instruction*> lesDeclarations)
		:Symbole(Symbole::Bi), instructions(lesDeclarations){}

	void addInstruction(Instruction* uneInstruction) {
		instructions.push_back(uneInstruction);
	}


	void exec(map<string, pair<double, bool> > *table);
	void print();
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

	virtual ~BlocInstruction(){}

protected:

	std::vector<Instruction*> instructions;
};


#endif /* BLOCINSTRUCTION_H_ */
