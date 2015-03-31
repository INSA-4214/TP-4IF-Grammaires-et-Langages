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
	virtual void print()=0;
    virtual void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) = 0;

};

class Variable : public Expr {
 public:
    Variable(std::string leNom, int laValeur)
 	 	 : Expr(), nom(leNom), valeur(laValeur) { }

    Variable()
     	 	 : Expr(){}

    void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

    std::string name() { return nom; }

    void setNom(std::string unNom) {
    	nom = unNom;
    }

    void print();
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

    void print();

    void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

 private:
    int valeur;
};

class BinExpr : public Expr {
 public:

	explicit BinExpr(Expr * left = NULL, Expr * right = NULL);

        void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

	    Expr * getLeft() const { return sym_gauche; }
	    Expr * getRight() const { return sym_droite; }

	    void setGauche(Expr *gauche) {
	    	sym_gauche = gauche;
	    }
	    void setDroite(Expr *droite) {
	    	sym_droite = droite;
	    }

	    virtual void print() = 0;


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

    void print();

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

    void print();

 protected:

    Operateur* operateur;
};


#endif /* EXPR_H_ */
