/*
 * BlocDeclaration.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#include "BlocDeclaration.h"
//*

void BlocDeclaration::multDeclaration(std::map<std::string, std::pair<bool, bool> > *table) {

	for ( std::set<DCst*>::iterator it = decConst.begin(); it != decConst.end(); ++it ) {

		(*it)->multDeclaration(table);
	}

	for (std::set<DVar*>::iterator it=decVar.begin(); it!=decVar.end(); ++it){

		(*it)->multDeclaration(table);
	}
}

void BlocDeclaration::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	for ( std::set<DCst*>::iterator it = decConst.begin(); it != decConst.end(); ++it ) {

		(*it)->staticAnalysis(table);
	}

	for (std::set<DVar*>::iterator it=decVar.begin(); it!=decVar.end(); ++it){

		(*it)->staticAnalysis(table);
	}
}

void BlocDeclaration::print() {

    constNumber = 0;
    varNumber = 0;

    while (constNumber + varNumber < isConst.size())
    {
        if (isConst[constNumber + varNumber] == true)
        {
            (*std::next(decConst.begin(), constNumber))->print();
            constNumber++;
        }
        else
        {
            (*std::next(decVar.begin(), varNumber))->print();
            varNumber++;
        }
    }
}

void BlocDeclaration::exec(map<string, pair<double, bool> > *table) {

	//Affichage set de declaration des const
	for ( std::set<DCst*>::iterator it = decConst.begin(); it != decConst.end(); ++it ) {

		(*it)->exec(table);
	}

	//Affichage set de declaration des var
	for (std::set<DVar*>::iterator it=decVar.begin(); it!=decVar.end(); ++it){

		(*it)->exec(table);
	}
}
//*/
