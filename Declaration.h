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

class Lc: public Symbole{

public:
	Lc(): Symbole(Symbole::Lc){}

	std::set< std::pair<Symbole*,int> > getPairsconst();

	void addidcons(Symbole* monSymb,int val);

	void setSetidvar(std::set< std::pair<Symbole*,int> > mesconst);

protected:

	std::set< std::pair<Symbole*,int> > pairsconst;
};

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
	DCst(): Symbole(Symbole::D){}

	std::set< std::pair<Symbole*,int> > getPairsconst();

	void addidcons(Symbole* monSymb,int val);

	void setSetidvar(std::set< std::pair<Symbole*,int> > mesconst);

protected:

	std::set< std::pair<Symbole*,int> > pairsconst;
};

#endif /* DECLARATION_H_ */
