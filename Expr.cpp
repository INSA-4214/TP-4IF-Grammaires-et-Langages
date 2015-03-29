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

Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

