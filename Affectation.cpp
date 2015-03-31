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
     std::map<std::string, std::pair<double, bool> >::iterator it = table->find(idALire);
    if (it == table->end() || it->second.second == 1) {
           cerr << "Cette variable n'a pas ete declaree" << endl;
}
    else{
        it->second.premier=(e->exec(table)):
}

void Affectation::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table){

}

