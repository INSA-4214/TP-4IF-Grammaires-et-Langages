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
    virtual double eval(const std::map<std::string, double> &valeurs);

    std::string name() { return nom; }

 protected:
	std::string nom;
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

	    Expr * left() const { return sym_gauche; }
	    Expr * right() const { return sym_droite; }
	    void left(Expr * left);
	    void right(Expr * right);

	    virtual double eval(const std::map<std::string, double> & values)=0;

 protected:
    Expr *sym_gauche;
    Expr *sym_droite;
};

class AddExpr : public BinExpr {
 public:
    explicit AddExpr(Symbole::Id id, Expr *left = NULL, Expr *right = NULL);

    virtual double eval(const std::map<std::string, double> & values);

 private:
};

class SubExpr : public BinExpr {
 public:
	explicit SubExpr(Symbole::Id id, Expr *left = NULL, Expr *right = NULL);
    virtual double eval(const std::map<std::string, double> & values);

 private:
};

class MultExpr : public BinExpr {
 public:
	explicit MultExpr(Symbole::Id id, Expr *left = NULL, Expr *right = NULL);
    virtual double eval(const std::map<std::string, double> & values);

 private:
};

class DivExpr : public BinExpr {
 public:
	explicit DivExpr(Symbole::Id id, Expr *left = NULL, Expr *right = NULL);
    virtual double eval(const std::map<std::string, double> & values);

 private:
};


#endif /* EXPR_H_ */
