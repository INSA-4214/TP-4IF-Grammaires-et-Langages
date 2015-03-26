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

BinExpr::BinExpr(Symbole::Id id, Expr * left, Expr * right)
    : Expr(id), sym_gauche(left), sym_droite(right) { }

AddExpr::AddExpr(Expr * left, Expr * right, Symbole* plus)
    : BinExpr(Symbole::E, left, right), operateur(plus) { }

MultExpr::MultExpr(Expr * left, Expr * right,  Symbole* mult)
    : BinExpr(Symbole::E, left, right), operateur(mult) { }


Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

