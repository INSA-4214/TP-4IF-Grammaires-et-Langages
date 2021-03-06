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
#include <map>

using namespace std;

class Lc: public Symbole{

public:
	Lc(): Symbole(Symbole::Lc){}

	std::set< std::pair<std::string,double> > getPairsconst();

	void addidcons(std::string uneConst,double val);

	void setPairsConst(std::set< std::pair<std::string,double> > mesconst);

protected:

	std::set< std::pair<std::string,double> > pairsconst;
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
 * Repr�sente toutes les variables d�clar�es sur une ligne
 */
class DVar: public Symbole{

public:


	DVar(): Symbole(Symbole::D){}

	std::set<std::string> getIdVars();

	void addidvar(std::string uneVar);

    void setIdvars(std::set<std::string> mesidvar);



    void exec(map<string, pair<double, bool> > *table);
	void multDeclaration(std::map<std::string, std::pair<bool, bool> > *table);
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
    void print();


protected:

	std::set<std::string> idVars;
};


class DCst: public Symbole{

public:
	DCst(): Symbole(Symbole::D){}

	std::set< std::pair<std::string,double> > getPairsconst();

	void addidcons(std::string maConst, double val);

	void setPairsConst(std::set< std::pair<std::string,double> > mesconst);

	void print();

	void multDeclaration(std::map<std::string, std::pair<bool, bool> > *table);
	void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

	void exec(map<string, pair<double, bool> > *table);

protected:

	std::set< std::pair<std::string,double> > pairsconst;
};

#endif /* DECLARATION_H_ */
