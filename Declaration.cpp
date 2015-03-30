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

void DVar::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it)
		table->insert(std::make_pair(0,0));
}

std::set< std::pair<std::string,int> > Lc::getPairsconst(){
    return pairsconst;
}

void Lc::addidcons(std::string maConst,int val){
    this->pairsconst.insert(std::make_pair( maConst, val));
}
void Lc::setPairsConst(std::set< std::pair<std::string,int> > mesconst){
 this->pairsconst=mesconst;
}

std::set< std::pair<std::string,int> > DCst::getPairsconst(){
    return this->pairsconst;
}

void DCst::addidcons(std::string maConst,int val){
    this->pairsconst.insert(std::make_pair( maConst, val));
}
void DCst::setPairsConst(std::set< std::pair<std::string,int> > mesconst){
	this->pairsconst=mesconst;
}

void DCst::printDCst(){
	for (std::set<std::pair<std::string,int> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it)
	    std::cout << "const " << (*it).first << " = " << (*it).second << " ; " << std::endl;
}

void DCst::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {
	for (std::set<std::pair<std::string,int> >::iterator it= pairsconst.begin(); it!=pairsconst.end(); ++it)
		table->insert(std::make_pair((*it).first,std::make_pair(1,1)));
}

void DVar::printDVar(){

	for (std::set<std::string>::iterator it= idVars.begin(); it!=idVars.end(); ++it)
		std::cout << "var " << *it << " ; " << std::endl;
}
//*/
