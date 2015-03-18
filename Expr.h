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

	Expr(Symbole::Id id) : Symbole(id){}
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
    explicit Number(Symbole::Id id) : Expr(id) { }

 private:
};

class BinExpr : public Expr {
 public:
	explicit BinExpr(Symbole::Id id,
	                     Expr * left = nullptr,
	                     Expr * right = nullptr);
	    ~BinExpr() {
	    	delete sym_gauche;
	    	delete sym_droite;
	    }

	    void left(Expr * left, bool shouldDelete = true);
	    void right(Expr * right, bool shouldDelete = true);
	    Expr * left() const { return sym_gauche; }
	    Expr * right() const { return sym_droite; }

 private:
    Expr *sym_gauche;
    Expr *sym_droite;
};

class AddExpr : public BinExpr {
 public:
    explicit AddExpr(Symbole::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class SubExpr : public BinExpr {
 public:
    explicit SubExpr(Symbole::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class MulExpr : public BinExpr {
 public:
    explicit MulExpr(Symbole::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};

class DivExpr : public BinExpr {
 public:
    explicit DivExpr(Symbole::Id id) : BinExpr(id) { }
    virtual uint64_t eval(const std::map<std::string, uint64_t> & values);

 private:
};


#endif /* EXPR_H_ */
