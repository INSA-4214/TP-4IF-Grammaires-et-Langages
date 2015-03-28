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

	Lv(): Symbole(Symbole::Lv){}

	std::set<Symbole*> getSetidvar();

	void addidvar(Symbole* monSymb);

	void setSetidvar(std::set<Symbole*> mesidvar);

protected:

	std::set<Symbole*> setidvar;
};

class DVar: public Symbole{

public:


	DVar(): Symbole(Symbole::D){}

	std::set<Symbole*> getSetidvar();

	void addidvar(Symbole* monSymb);

    void setSetidvar(std::set<Symbole*> mesidvar);
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
