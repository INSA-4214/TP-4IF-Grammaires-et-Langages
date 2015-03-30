#include "Affectation.h"
#include <iostream>
#include <map>
using namespace std;

void Affectation::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	map<string, pair<bool, bool> >::iterator it = table->find(m_idVar);

	if (it == table->end()) {

		cerr << "La variable " << m_idVar << " n'a pas ete declaree" << endl;

	} else if (it->second.second == 1) {

		cerr <<  m_idVar << " est une constante" << endl;

	} else {

		it->second.first = 1;

	}

	e->staticAnalysis(table);


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


