/*
 * Declaration.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#include "Declaration.h"


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
