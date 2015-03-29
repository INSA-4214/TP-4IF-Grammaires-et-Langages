/*
 * Declaration.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Vincent
 */

#include "Declaration.h"


std::set<Symbole*> Lv::getSetidvar(){
        return this->setidvar;
	}

void Lv::addidvar(Symbole* monSymb){
    setidvar.insert(monSymb);
}

void Lv::setSetidvar(std::set<Symbole*> mesidvar){
    this->setidvar = mesidvar;
}

std::set<Symbole*> DVar::getSetidvar(){
        return this->setidvar;
	}

void DVar::addidvar(Symbole* monSymb){
    setidvar.insert(monSymb);
}

void DVar::setSetidvar(std::set<Symbole*> mesidvar){
    this->setidvar = mesidvar;
}

std::set< std::pair<Symbole*,int> > Lc::getPairsconst(){
    return this->pairsconst;
}

void Lc::addidcons(Symbole* monSymb,int val){
    this->pairsconst.insert(std::make_pair( monSymb, val));
}
void Lc::setSetidvar(std::set< std::pair<Symbole*,int> > mesconst){
 this->pairsconst=mesconst;
}

std::set< std::pair<Symbole*,int> > DCst::getPairsconst(){
    return this->pairsconst;
}

void DCst::addidcons(Symbole* monSymb,int val){
    this->pairsconst.insert(std::make_pair( monSymb, val));
}
void DCst::setSetidvar(std::set< std::pair<Symbole*,int> > mesconst){
 this->pairsconst=mesconst;
}
