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

	cout << m_idVar << " := ";
	(*e).print();
	cout << " ;" << endl;
}

void Affectation::exec(map<string, pair<double, bool> > *table){
     std::map<std::string, std::pair<double, bool> >::iterator it = table->find(m_idVar);
    if (it == table->end() || it->second.second == 1) {
           cerr << "Cette variable n'a pas ete declaree" << endl;
}
    else
        it->second.first=(e->exec(table));
}


