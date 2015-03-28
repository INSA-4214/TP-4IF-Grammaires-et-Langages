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

std::set<Symbole*> DVar::getSetidvar(){
        return this->setidvar;
	}

void DVar::addidvar(Symbole* monSymb){
    setidvar.insert(monSymb);
}
