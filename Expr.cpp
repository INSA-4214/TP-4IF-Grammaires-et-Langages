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

	} else if (it == table->end() && it->second.second == 1) {

		cerr << "La constante " << nom << " n'a pas ete declaree" << endl;

	} else if (it->second.first < 1 && it->second.second < 1) {

		cerr << "La variable " << nom << " n'est pas affectee" << endl;

	}
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
	cout << sym_gauche->getStr();
	sym_gauche->staticAnalysis(table);
	sym_droite->staticAnalysis(table);
}

void Nombre::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}


Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

