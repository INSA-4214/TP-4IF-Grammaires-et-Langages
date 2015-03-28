/*
 * Declaration.h
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#ifndef DECLARATION_H_
#define DECLARATION_H_
#include "Symbole.h"
#include <set>


class Lv: public Symbole{

public:

	Lv(std::set<Symbole*> setLv): Symbole(Symbole::Lv),setidvar(setLv){}

	std::set<Symbole*> getSetidvar();

	void addidvar(Symbole* monSymb);

protected:

	std::set<Symbole*> setidvar;
};

class DVar: public Symbole{

public:


	DVar(std::set<Symbole*> setLv): Symbole(Symbole::D),setidvar(setLv){}

	std::set<Symbole*> getSetidvar();

	void addidvar(Symbole* monSymb);

protected:

	std::set<Symbole*> setidvar;
};


class DCst: public Symbole{

public:

	DCst(Symbole::Id id, int val) : Symbole(id), valeur(val){}

protected:

	int valeur;
};

#endif /* DECLARATION_H_ */
