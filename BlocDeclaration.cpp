/*
 * BlocDeclaration.cpp
 *
 *  Created on: 26 mars 2015
 *      Author: Huber
 */

#include "BlocDeclaration.h"
//*

void BlocDeclaration::staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table) {

	for ( std::set<DCst*>::iterator it = decConst.begin(); it != decConst.end(); ++it ) {

		(*it)->staticAnalysis(table);
	}

	for (std::set<DVar*>::iterator it=decVar.begin(); it!=decVar.end(); ++it){

		(*it)->staticAnalysis(table);
	}
}

void BlocDeclaration::printBlocD() {

	//Affichage set de declaration des const
	for ( std::set<DCst*>::iterator it = decConst.begin(); it != decConst.end(); ++it ) {

		(*it)->printDCst();
	}

	//Affichage set de declaration des var
	for (std::set<DVar*>::iterator it=decVar.begin(); it!=decVar.end(); ++it){

		(*it)->printDVar();
	}
}

//*/
