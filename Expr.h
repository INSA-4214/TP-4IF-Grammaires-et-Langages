/*
 * Expr.h
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#ifndef EXPR_H_
#define EXPR_H_

#include "Symbole.h"
#include <map>
#include <string>

class Expr : public Symbole {

public:
	const int EXPR = 1;

	Expr():Symbole(EXPR){}
	virtual ~Expr();

	virtual double eval(const std::map<std::string, double> &valeurs) = 0;

};

class Variable : public Expr {
 public:
    Variable(Symbole::Id id) : Expr(id) { }

 private:
};

class Number : public Expr {
 public:
    explicit Number(Token::Id id) : Expr(id) { }

 private:
};

class BinExpr : public Expr {
 public:
    explicit BinExpr(Token::Id id) : Expr(id) { }

 private:
    Expr *left;
    Expr *right;
};

class AddExpr : public BinExpr {
 public:
    explicit AddExpr(Token::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class SubExpr : public BinExpr {
 public:
    explicit SubExpr(Token::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class MulExpr : public BinExpr {
 public:
    explicit MulExpr(Token::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class DivExpr : public BinExpr {
 public:
    explicit DivExpr(Token::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};


#endif /* EXPR_H_ */
