/*
 * Programme.h
 *
 *  Created on: 28 mars 2015
 *      Author: Huber
 */

#ifndef PROGRAMME_H_
#define PROGRAMME_H_

#include <map>
#include <string>
#include "BlocInstruction.h"
#include "BlocDeclaration.h"

class Programme: public Symbole {
public:

	Programme()
		:Symbole(Symbole::P), blocI(new BlocInstruction()), blocD(new BlocDeclaration()){}

	Programme(BlocInstruction *unBlocI, BlocDeclaration *unBlocD)
		:Symbole(Symbole::P), blocI(unBlocI), blocD(unBlocD){}

	void setBlocI(BlocInstruction* unBlocI) {
		blocI = unBlocI;
	}

	void setBlocD(BlocDeclaration* unBlocD) {
		blocD = unBlocD;
	}

	void multDeclaration(std::map<std::string, std::pair<bool, bool> > *table);
	void print();
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
	void transform();

	void exec(map<string, pair<double, bool> > *table);

	virtual ~Programme();

protected:
	BlocInstruction* blocI;
	BlocDeclaration* blocD;
};

#endif /* PROGRAMME_H_ */
