/*
 * Automate.cpp
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#include "Automate.h"
#include "Etats/Etat00.h"

Automate::~Automate() {

}

Automate::Automate(Lexer *unlexer) {

	lexer = unlexer;
	pileEtats.push(new Etat00());
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
            //symbole courant
        if ( pileEtats.empty() )
            return false;
        Symbole *s = lexer->getSymboleCourant();
        if ( s == NULL )
            return false;
        if ( !pileEtats.top()->transition(this, s) )
            return false;
        }
        if ( pileEtats.empty() )
            return false;
        return true;

}


std::stack<Etat*> *Automate::getPileEtats(){

	return &this->pileEtats;
}
std::stack<Symbole*> *Automate::getPileSymboles(){

	return &this->pileSymboles;
}

void Automate::setAccepter(bool b){
	this->accepte = b;
}
