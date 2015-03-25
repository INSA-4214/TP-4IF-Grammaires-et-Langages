/*
 * Automate.cpp
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#include "Automate.h"

Automate::~Automate() {

}

Automate::Automate(std::istream * stream) {

	lexer = new Lexer(stream);
	//TODO init pileEtat
	accepte = false;

}

void decalage(Symbole s, Etat e){

	Automate::pileEtats.push(e);
	Automate::pileSymboles.push(s);

}
bool Automate::lecture(){
	//TODO get Token de la pile
	//TODO boucle exploration
	lexer.shift();
	if( pileEtats.empty() )
		return false;
	return accepte;
}

std::stack<Etat> getPileEtats(){

	return Automate::pileEtats;
}
std::stack<Symbole> getPileSymboles(){

	return Automate::pileSymboles;
}

void Automate::setAccepter(bool b){
	this->accepte = b;
}
