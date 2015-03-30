/*
 * Expr.cpp
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#include <map>
#include <cstdlib>
#include "Expr.h"

// ----- Constructeurs -----

BinExpr::BinExpr(Expr * left, Expr * right)
    : Expr(), sym_gauche(left), sym_droite(right) { }

void Variable::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void Constante::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void BinExpr::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void Nombre::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}


Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

