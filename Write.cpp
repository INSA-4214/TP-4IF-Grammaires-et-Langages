#include "Write.h"
#include <iostream>



void Write::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	e->staticAnalysis(table);
}


Write::~Write()
{
    //dtor
}

void Write::print(){
    cout << "ecrire ";
	(*e).print();
	cout << ";" << std::endl;

}
void Write::exec(map<string, pair<double, bool> > *table){
    double b = e->exec(table);
    std::cout << b << std::endl;

}

