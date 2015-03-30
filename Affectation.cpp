#include "Affectation.h"
#include <stdio.h>
#include <map>
void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

}


Affectation::~Affectation()
{
    //dtor
}
void Affectation::print(){

	//Cast de e en nombre
	Nombre *n = (Nombre*)e;
	//std::cout << m_idVar << " := " <<  n->getValeur() << " ;"<< std::endl;
}

void Affectation::exec(map<string, pair<double, bool> > *table){

}

void Affectation::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table){

}

