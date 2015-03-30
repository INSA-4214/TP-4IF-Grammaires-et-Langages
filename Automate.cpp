/*
 * Automate.cpp
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */


#include "Automate.h"
#include "Etats/Etat00.h"
#include <stdio.h>
#include "Programme.h"

using namespace std;

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

        if ( !pileEtats.top()->transition(this, s) ) {
                while( !pileEtats.empty()){
                    cout << "Erreur : Transition non envisagee pour l'etat " << pileEtats.top()->numEtat() << endl;
                    pileEtats.pop();
                }
                cout << "Symbole courant : " << s->getIdent() << endl;
                while( !pileSymboles.empty()){
                    cout << "Symbole pile : " << pileSymboles.top()->getIdent() << endl;
                    cout << "Symbole pile : " << pileSymboles.top()->getStr() << endl;

                    pileSymboles.pop();
                }

            //return false;
        }
    }
    return true;

}

void Automate::erreurSyntax(std::string type) {
    int *pos = lexer->getCurrPos();
    cerr << "Erreur syntaxique (" << pos[0] << ":" << pos[1] << ") " << type << endl;
}

void Automate::erreurSyntax(std::string type, std::string strAtt) {
    int *pos = lexer->getCurrPos();
    cerr << "Erreur syntaxique (" << pos[0] << ":" << pos[1] << ") " << type << " " << strAtt << " attendu" << endl;
}

void Automate::erreurSyntax(std::string type, std::string strAtt, std::string strAtt2) {
    int *pos = lexer->getCurrPos();
    cerr << "Erreur syntaxique (" << pos[0] << ":" << pos[1] << ") " << type << " " << strAtt << " ou " << strAtt2 << " attendu" << endl;
}

std::stack<Etat*> *Automate::getPileEtats(){

	return &this->pileEtats;
}
std::stack<Symbole*> *Automate::getPileSymboles(){

	return &this->pileSymboles;
}

void Automate::setAccepter(bool b){
    cout << "... Parsing termine !" << endl;
	this->accepte = b;
}

void Automate::print()
{
	// Recuperation du programme parse
	Programme * p = (Programme *) pileSymboles.top();
	p->print();
}

void Automate::staticAnalysis()
{
	// Recuperation du programme parse
	Programme * p = (Programme *) pileSymboles.top();
	p->staticAnalysis();
}

void Automate::exec()
{
	// Recuperation du programme parse
	Programme * p = (Programme *) pileSymboles.top();

	p->exec();
}

void Automate::transform(){

	// Recuperation du programme parse
	Programme * p = (Programme *) pileSymboles.top();
	p->transform();
}
