/*
 * Expr.h
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#ifndef EXPR_H_
#define EXPR_H_

#include <map>
#include <string>
#include "Symbole.h"

class Expr : public Symbole {

public:

	Expr(Symbole::Id id) : Symbole(id){}
	virtual ~Expr();

	virtual double eval(const std::map<std::string, double> &valeurs) = 0;

};

class Variable : public Expr {
 public:
    Variable(std::string leNom, int laValeur)
 	 	 : Expr(Symbole::var), nom(leNom), valeur(laValeur) { }

    std::string name() { return nom; }

 protected:
	std::string nom;
	int valeur;
};

class Constante : public Expr {
 public:
    Constante(std::string leNom, int laValeur)
 	 	 : Expr(Symbole::cst), nom(leNom), valeur(laValeur) { }

    std::string name() { return nom; }

 protected:
	std::string nom;
	int valeur;
};

class Nombre : public Expr {
 public:
    explicit Nombre(int uneValeur)
    	: Expr(Symbole::nb), valeur(uneValeur) { }

 private:
    int valeur;
};

class BinExpr : public Expr {
 public:
	explicit BinExpr(Symbole::Id id,
	                     Expr * left = NULL,
	                     Expr * right = NULL);

	    ~BinExpr() {
	    	delete sym_gauche;
	    	delete sym_droite;
	    }

	    Expr * getLeft() const { return sym_gauche; }
	    Expr * getRight() const { return sym_droite; }

 protected:
    Expr *sym_gauche;
    Expr *sym_droite;
};

class AddExpr : public BinExpr {
 public:

    explicit AddExpr(Expr *left, Expr *right, Symbole* plus);

    virtual ~AddExpr(){
    	delete operateur;
    }

    Symbole* const getOperateur(){return operateur;}

 protected:

    Symbole* operateur;
};

class MultExpr : public BinExpr {
 public:

	explicit MultExpr(Expr *left , Expr *right, Symbole* mult);

    virtual ~MultExpr(){
    	delete operateur;
    }

    Symbole* const getOperateur(){return operateur;}

 protected:

    Symbole* operateur;
};


#endif /* EXPR_H_ */
