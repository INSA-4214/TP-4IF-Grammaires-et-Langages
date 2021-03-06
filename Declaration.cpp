/*
 * Declaration.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#include "Declaration.h"
#include <iostream>

std::set<std::string> Lv::getSetidvar(){
	return idVars;
}

void Lv::addidvar(std::string uneVar){
    idVars.insert(uneVar);
}

std::set<std::string> DVar::getIdVars(){
    return this->idVars;
}

void DVar::addidvar(std::string uneVar){
    idVars.insert(uneVar);
}

void DVar::setIdvars(std::set<std::string> mesidvar){
    idVars = mesidvar;
}

void DVar::multDeclaration(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it){


        auto it2= table->find((*it));
		if (!(it2 == table->end()))
            cerr << "la variable " + (*it) + " est deja declaree" << endl;
		else
        {
            table->insert(std::make_pair((*it),std::make_pair(1,1)));
        }
	}


}

void DVar::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it){
		table->insert(std::make_pair((*it),std::make_pair(0,0)));
	}
}
std::set< std::pair<std::string,double> > Lc::getPairsconst(){
    return pairsconst;
}

void Lc::addidcons(std::string maConst,double val){
    this->pairsconst.insert(std::make_pair( maConst, val));
}
void Lc::setPairsConst(std::set< std::pair<std::string,double> > mesconst){
 this->pairsconst=mesconst;
}

std::set< std::pair<std::string,double> > DCst::getPairsconst(){
    return this->pairsconst;
}

void DCst::addidcons(std::string maConst,double val){
    this->pairsconst.insert(std::make_pair( maConst, val));
}
void DCst::setPairsConst(std::set< std::pair<std::string,double> > mesconst){
	this->pairsconst=mesconst;
}


void DCst::print(){
	for (std::set<std::pair<std::string,double> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it)
	    std::cout << "const " << (*it).first << " = " << (*it).second << ";" << std::endl;
}

void DCst::multDeclaration(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::pair<std::string,double> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it){


        auto it2= table->find((*it).first);
		if (!(it2 == table->end()))
            cerr << "la constante " + (*it).first + " est deja declaree" << endl;
		else
            table->insert(std::make_pair((*it).first,std::make_pair(1,1)));
	}


}

void DCst::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::pair<std::string,double> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it){
		table->insert(std::make_pair((*it).first,std::make_pair(1,1)));
	}


}

void DVar::print(){

	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it)
		std::cout << "var " << *it << ";" << std::endl;
}
//*/

void DVar::exec(map<string, pair<double, bool> > *table){

	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it)
		table->insert(std::make_pair((*it),std::make_pair(NULL,0)));
}
//*/

void DCst::exec(map<string, pair<double, bool> > *table){
	for (std::set<std::pair<std::string,double> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it)
	     table->insert(std::make_pair((*it).first,std::make_pair((*it).second,1)));

}
