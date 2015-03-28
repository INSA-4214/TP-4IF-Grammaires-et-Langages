/*
 * Declaration.h
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#ifndef DECLARATION_H_
#define DECLARATION_H_
#include "Symbole.h"

class Declaration : public Symbole{
public:
	Declaration(Symbole::Id id) : s(Symbole(id)){}
	virtual ~Declaration();


protected:
	Symbole s;

};

class DVar : public Declaration{

public:

	DVar(Symbole::Id id): Declaration(id){}
};

class DCst : public Declaration{

public:

	DCst(Symbole::Id id, int val) : Declaration(id), valeur(val){}

protected:

	int valeur;
};

#endif /* DECLARATION_H_ */
