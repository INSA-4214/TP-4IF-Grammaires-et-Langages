#include "Read.h"
#include <iostream>

void Read::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {


}

Read::~Read()
{
    //dtor
}

void Read::print(){

}

void Read::exec(map<string, pair<double, bool> > *table){
    double a;
     std::cin >>a;
     std::map<std::string, std::pair<double, bool> >::iterator it = table->find(idALire);
    if (it == table->end() || it->second.second == 1) {
           cerr << "Cette variable n'a pas ete declaree" << endl;
}
    else{
        it->second.premier=a:
    }
}

