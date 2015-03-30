/*
 * Expr.h
 *
 *  Created on: 9 mars 2015
 *      Author: Huber
 */

#ifndef EXPR_H_
#define EXPR_H_

#include "Operateur.h"
#include <map>
#include <string>
#include "Symbole.h"

class Expr : public Symbole {

public:

	Expr() : Symbole(Symbole::E){}
	virtual ~Expr();
};

class Variable : public Expr {
 public:
    Variable(std::string leNom, int laValeur)
 	 	 : Expr(), nom(leNom), valeur(laValeur) { }

    Variable()
     	 	 : Expr(){}

    std::string name() { return nom; }

    void setNom(std::string unNom) {
    	nom = unNom;
    }

 protected:
	std::string nom;
	int valeur;
};

class Constante : public Expr {
 public:
    Constante(std::string leNom, int laValeur)
 	 	 : Expr(), nom(leNom), valeur(laValeur) { }

    std::string name() { return nom; }

 protected:
	std::string nom;
	int valeur;
};

class Nombre : public Expr {
 public:
    explicit Nombre(int uneValeur)
    	: Expr(), valeur(uneValeur) { }

    explicit Nombre()
    	: Expr(){}

    const int getValeur() {
    	return valeur;
    }

    void setValeur(int uneValeur) {
    	valeur = uneValeur;
    }

 private:
    int valeur;
};

class BinExpr : public Expr {
 public:
	explicit BinExpr(Expr * left = NULL, Expr * right = NULL);

	    ~BinExpr() {
	    	delete sym_gauche;
	    	delete sym_droite;
	    }

	    Expr * getLeft() const { return sym_gauche; }
	    Expr * getRight() const { return sym_droite; }

	    void setGauche(Expr *gauche) {
	    	sym_gauche = gauche;
	    }
	    void setDroite(Expr *droite) {
	    	sym_droite = droite;
	    }


 protected:
    Expr *sym_gauche;
    Expr *sym_droite;
};

class AddExpr : public BinExpr {
 public:

    explicit AddExpr()
    	:BinExpr(){}

    virtual ~AddExpr(){
    	delete operateur;
    }

    Symbole* const getOperateur(){return operateur;}

    void setOperateur(Operateur *ope) {
    	operateur = ope;
    }

 protected:

    Operateur* operateur;
};

class MultExpr : public BinExpr {
 public:

	explicit MultExpr()
		:BinExpr(){}

    virtual ~MultExpr(){
    	delete operateur;
    }

    Symbole* const getOperateur(){return operateur;}

    void setOperateur(Operateur *ope) {
    	operateur = ope;
    }

 protected:

    Operateur* operateur;
};


#endif /* EXPR_H_ */
