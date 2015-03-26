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

class BlocDeclaration: public Symbole {
public:

	BlocDeclaration()
		:Symbole(Symbole::Bd), declarations(std::set<Declaration*>()){}

	BlocDeclaration(std::set<Declaration*> lesDeclarations)
		:Symbole(Symbole::Bd), declarations(lesDeclarations){}

	virtual ~BlocDeclaration(){}

protected:

	std::set<Declaration*> declarations;
};

#endif /* BLOCDECLARATION_H_ */
