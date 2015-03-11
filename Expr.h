/*
 * Expr.h
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#ifndef EXPR_H_
#define EXPR_H_

#include "Symbole.h"
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/include/map_fwd.hpp>
#include <boost/any.hpp>
#include <map>

class Expr : public Symbole {

public:
	const int EXPR = 1;

	Expr():Symbole(EXPR){}
	virtual ~Expr();

	virtual double eval(const std::map<std::string, double> &valeurs) = 0;


};

#endif /* EXPR_H_ */
