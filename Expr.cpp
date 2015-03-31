/*
 * Expr.cpp
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#include <map>
#include <iostream>
#include <cstdlib>
#include "Expr.h"

using namespace std;

// ----- Constructeurs -----

BinExpr::BinExpr(Expr * left, Expr * right)
    : Expr(), sym_gauche(left), sym_droite(right) { }

void Variable::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	std::map<std::string, std::pair<bool, bool> >::iterator it = table->find(nom);

	if (it == table->end() && it->second.second < 1) {

		cerr << "La variable " << nom << " n'a pas ete declaree" << endl;

	} else if (it->second.first < 1 && it->second.second < 1) {

		cerr << "La variable " << nom << " n'est pas affectee" << endl;

	}
}

void Constante::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	std::map<std::string, std::pair<bool, bool> >::iterator it = table->find(nom);

	if (it == table->end() || it->second.second < 1) {

		cerr << "Cette constante n'a pas ete declaree" << endl;

	} else if (it->second.first < 1) {

		cerr << "Cette constante n'est pas affectee" << endl;

	}

}

void Constante::print() {

	std::cout <<  name();
}

void Variable::print() {

	std::cout << name();
}

void Nombre::print() {

	std::cout << getValeur();
}

void MultExpr::print(){

	string symOp = "";
	if(operateur->getope())
		symOp = " * ";
	else
		symOp = " / ";
	sym_gauche->print();
	cout << symOp;
	sym_droite->print();

}

void AddExpr::print(){

	string symOp = "";
	if(operateur->getope())
		symOp = " + ";
	else
		symOp = " - ";
	sym_gauche->print();
	cout << symOp;
	sym_droite->print();

}

void BinExpr::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	sym_gauche->staticAnalysis(table);
	sym_droite->staticAnalysis(table);
}

void Nombre::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}
double Nombre::exec(map<string, pair<double, bool> > *table){
    return getValeur();
}

double AddExpr::exec(map<string, pair<double, bool> > *table){
    if(operateur->getope())
        return (double)sym_gauche->exec(table) +(double) sym_droite->exec(table);
    else
        return (double)sym_gauche->exec(table) -(double) sym_droite->exec(table);
}
double MultExpr::exec(map<string, pair<double, bool> > *table){
     if(operateur->getope())
        return (double)sym_gauche->exec(table) * (double) sym_droite->exec(table);
    else
        return (double)sym_gauche->exec(table) / (double) sym_droite->exec(table);
}
double Constante::exec(map<string, pair<double, bool> > *table){
    std::map<std::string, std::pair<double, bool> >::iterator it = table->find(nom);
    if (it == table->end() || it->second.second == 0) {
        return it->second.first;//on a trouvé la contante
    }
    else  {
        cerr << "La contante n existe pas" << endl;
        return 0;
    }
}
double Variable::exec(map<string, pair<double, bool> > *table){
    std::map<std::string, std::pair<double, bool> >::iterator it = table->find(nom);
    if (it == table->end() || it->second.second == 1) {
        if(it->second.first!=NULL)
            return it->second.first;//on a trouvé la variable
    }
    else  {
        cerr << "La variable n existe pas" << endl;
        return 0;
    }
}
Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

