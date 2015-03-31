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

    virtual void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) = 0;

    virtual double exec(map<string, pair<double, bool> > *table)=0;

};

class Variable : public Expr {
 public:
    Variable(std::string leNom, int laValeur)
 	 	 : Expr(), nom(leNom), valeur(laValeur) { }

    Variable()
     	 	 : Expr(){}

    void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

    std::string name() { return nom; }
    double exec(map<string, pair<double, bool> > *table);
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
    double exec(map<string, pair<double, bool> > *table);
    void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

 protected:
	std::string nom;
	int valeur;
};

class Nombre : public Expr {
 public:
    explicit Nombre(double uneValeur)
    	: Expr(), valeur(uneValeur) { }

    explicit Nombre()
    	: Expr(){}

    const double getValeur() {
    	return valeur;
    }

    void setValeur(doucle uneValeur) {
    	valeur = uneValeur;
    }
    double exec(map<string, pair<double, bool> > *table);
    void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

 private:
    double valeur;
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
    virtual double exec(map<string, pair<double, bool> > *table)=0;

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
    double exec(map<string, pair<double, bool> > *table);
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
    double exec(map<string, pair<double, bool> > *table);
 protected:

    Operateur* operateur;
};


#endif /* EXPR_H_ */
