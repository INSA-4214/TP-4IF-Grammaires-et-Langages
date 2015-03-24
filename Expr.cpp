/*
 * Expr.cpp
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#include "Expr.h"
#include <map>
#include <cstdlib>

void BinExpr::left(Expr *left) {
	sym_gauche = left;
}

void BinExpr::right(Expr *left) {
	sym_gauche = left;
}

// ----- Constructeurs -----

BinExpr::BinExpr(Symbole::Id id, Expr * left, Expr * right)
    : Expr(id), sym_gauche(left), sym_droite(right) { }

AddExpr::AddExpr(Symbole::Id id, Expr * left, Expr * right)
    : BinExpr(id, left, right) { }

SubExpr::SubExpr(Symbole::Id id, Expr * left, Expr * right)
    : BinExpr(id, left, right) { }

MultExpr::MultExpr(Symbole::Id id, Expr * left, Expr * right)
    : BinExpr(id, left, right) { }

DivExpr::DivExpr(Symbole::Id id, Expr * left, Expr * right)
    : BinExpr(id, left, right) { }

// ----- FIN Constructeurs -----

double Variable::eval(const std::map<std::string, double> &valeurs) {
	std::map<std::string, double>::iterator it=valeurs.find(nom);
	if (it == valeurs.end() || !(it->second)) {
		std::exit(EXIT_FAILURE);
	}
	return it->second;
}

double AddExpr::eval(const std::map<std::string, double> & valeurs) {
	double resultat = sym_gauche->eval(valeurs) + sym_droite->eval(valeurs);
	return resultat;
}

double SubExpr::eval(const std::map<std::string, double> & valeurs) {
	double resultat = sym_gauche->eval(valeurs) - sym_droite->eval(valeurs);
	return resultat;
}

double MultExpr::eval(const std::map<std::string, double> & valeurs) {
	double resultat = sym_gauche->eval(valeurs) * sym_droite->eval(valeurs);
	return resultat;
}

double DivExpr::eval(const std::map<std::string, double> & valeurs) {
	double resultat = sym_gauche->eval(valeurs) / sym_droite->eval(valeurs);
	return resultat;
}

Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

