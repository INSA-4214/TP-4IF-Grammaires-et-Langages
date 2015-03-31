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

BinExpr::BinExpr(Expr * left, Expr * right)
    : Expr(), sym_gauche(left), sym_droite(right) { }

void Variable::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void Constante::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void BinExpr::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}

void Nombre::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}
double Nombre::exec(map<string, pair<double, bool> > *table){
    return getValeur();
}

double AddExpr::exec(map<string, pair<double, bool> > *table){
    if(Operateur->getOpe())
        return (double)exec(sym_gauche) +(double) exec(sym_droite);
    else
        return (double)exec(sym_gauche) - (double)exec(sym_droite);
}
double MultExpr::exec(map<string, pair<double, bool> > *table){
    if(Operateur->getOpe())
        return (double)exec(sym_gauche) * (double)exec(sym_droite);
    else
        return (double)exec(sym_gauche) / (double)exec(sym_droite);
}
double Constante::exec(map<string, pair<double, bool> > *table){
    std::map<std::string, std::pair<double, bool> >::iterator it = table->find(nom);
    if (it == table->end() || it->second.second == 0) {
        return it->second.first;//on a trouvé la contante
    }
    else  {
        cerr << "La contante n existe pas" << endl;
        return 0;
    }
}
double Variable::exec(map<string, pair<double, bool> > *table){
    std::map<std::string, std::pair<double, bool> >::iterator it = table->find(nom);
    if (it == table->end() || it->second.second == 1) {
        if(it->second.first!=NULL)
            return it->second.first;//on a trouvé la variable
    }
    else  {
        cerr << "La variable n existe pas" << endl;
        return 0;
    }
}
Expr::~Expr() {
	// TODO Auto-generated destructor stub
}

