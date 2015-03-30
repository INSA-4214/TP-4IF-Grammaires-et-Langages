#include "Affectation.h"
#include <iostream>

using namespace std;

void Affectation::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	map<string, pair<bool, bool> >::iterator it = table->find(m_idVar);

	if (it == table->end() || it->second.second == 1) {

		cerr << "Cette variable n'a pas ete declaree" << endl;

	}

	e->staticAnalysis(table);

}


Affectation::~Affectation()
{
    //dtor
}
