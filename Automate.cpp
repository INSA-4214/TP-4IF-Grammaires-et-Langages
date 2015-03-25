/*
 * Automate.cpp
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#include "Automate.h"

Automate::~Automate() {

}

Automate::Automate(Lexer *unlexer) {

	lexer = unlexer;
	//TODO init pileEtat
	accepte = false;

}

void Automate::decalage(Symbole *s, Etat *e){

	this->pileEtats.push(e);
	this->pileSymboles.push(s);

}

bool Automate::lecture(){
	//TODO get Token de la pile
	//TODO boucle exploration
    while (lexer->getSymboleCourant()->getIdent() != Symbole::FILEEND) {
    	lexer->shift();
    }
	//if( pileEtats.empty() )
	//	return false;
	//return accepte;
}

std::stack<Etat*> Automate::getPileEtats(){

	return this->pileEtats;
}
std::stack<Symbole*> Automate::getPileSymboles(){

	return this->pileSymboles;
}

void Automate::setAccepter(bool b){
	this->accepte = b;
}
