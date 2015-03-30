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

	std::set< std::pair<std::string,int> > getPairsconst();

	void addidcons(std::string uneConst,int val);

	void setPairsConst(std::set< std::pair<std::string,int> > mesconst);

protected:

	std::set< std::pair<std::string,int> > pairsconst;
};

class Lv: public Symbole{

public:

	Lv(): Symbole(Symbole::Lv){}

	std::set<std::string> getSetidvar();

	void addidvar(std::string uneVar);

	void setIdVars(std::set<std::string> mesidvar);

protected:

	std::set<std::string> idVars;
};


/**
 * Représente toutes les variables déclarées sur une ligne
 */
class DVar: public Symbole{

public:


	DVar(): Symbole(Symbole::D){}

	std::set<std::string> getIdVars();

	void addidvar(std::string uneVar);

    void setIdvars(std::set<std::string> mesidvar);

	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
    void print();
protected:

	std::set<std::string> idVars;
};


class DCst: public Symbole{

public:
	DCst(): Symbole(Symbole::D){}

	std::set< std::pair<std::string,int> > getPairsconst();

	void addidcons(std::string maConst, int val);

	void setPairsConst(std::set< std::pair<std::string,int> > mesconst);

	void print();

	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

protected:

	std::set< std::pair<std::string,int> > pairsconst;
};

#endif /* DECLARATION_H_ */
