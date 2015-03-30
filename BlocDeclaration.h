/*
 * BlocDeclaration.h
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#ifndef BLOCDECLARATION_H_
#define BLOCDECLARATION_H_

#include "Declaration.h"
#include "Symbole.h"
#include <set>
#include <map>

class BlocDeclaration: public Symbole {
public:

	BlocDeclaration()
		:Symbole(Symbole::Bd), decConst(std::set<DCst*>()), decVar(std::set<DVar*>()){}

	BlocDeclaration(std::set<DVar*> lesDeclarationsVar, std::set<DCst*> lesDeclarationsConst)
		:Symbole(Symbole::Bd), decConst(lesDeclarationsConst), decVar(lesDeclarationsVar){}

	void addConst(DCst* uneDCst) {
		decConst.insert(uneDCst);
	}

	void addVar(DVar* uneDVar) {
		decVar.insert(uneDVar);
	}

	void print();
	void exec();
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

	virtual ~BlocDeclaration(){}

protected:

	std::set<DCst*> decConst;
	std::set<DVar*> decVar;
};

#endif /* BLOCDECLARATION_H_ */
