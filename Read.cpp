#include "Read.h"
#include <iostream>

using namespace std;

void Read::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {


	std::map<std::string, std::pair<bool, bool> >::iterator it = table->find(idALire);

	if (it == table->end()) {

		cerr << "Cette variable n'a pas ete declaree" << endl;

	} else if (it->second.second == 1) {

		cerr << "Vous essayez d'assigner une valeur a une constante" <<endl;

	} else {

		it->second.first = 1;

	}

}



Read::~Read()
{
    //dtor
}

void Read::print(){

	std::cout << "lire " << getIdALire() << " ;"<< std::endl;
}

void Read::exec(map<string, pair<double, bool> > *table){

}

