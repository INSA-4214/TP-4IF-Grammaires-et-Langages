/*
 * Automate.cpp
 *
 *  Created on: 4 mars 2015
 *      Author: Huber
 */

#include "Automate.h"

Automate::~Automate() {

}

Automate::Automate() {

	//Etat 0
	transitions[Etat::E0][Symbole::P] = new DeplacerTrans(Etat::E1);
	transitions[Etat::E0][Symbole::Bd] = new DeplacerTrans(Etat::E2);

	//Etat 2
	transitions[Etat::E2][Symbole::D] = new DeplacerTrans(Etat::E5);
	transitions[Etat::E2][Symbole::Bi] = new DeplacerTrans(Etat::E4);

	//Etat 4
	transitions[Etat::E4][Symbole::I] = new DeplacerTrans(Etat::E9);

	//Etat 10
	transitions[Etat::E10][Symbole::E] = new DeplacerTrans(Etat::E19);

	//Etat 19
	transitions[Etat::E19][Symbole::moins] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E19][Symbole::plus] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E19][Symbole::multi] = new DeplacerTrans(Etat::E29);
	transitions[Etat::E19][Symbole::divi] = new DeplacerTrans(Etat::E29);

	//Etat 20
	transitions[Etat::E20][Symbole::E] = new DeplacerTrans(Etat::E30);

	//Etat 21
	transitions[Etat::E21][Symbole::E] = new DeplacerTrans(Etat::E31);

	//Etat 28
	transitions[Etat::E28][Symbole::E] = new DeplacerTrans(Etat::E34);

	//Etat 29
	transitions[Etat::E29][Symbole::E] = new DeplacerTrans(Etat::E35);

	//Etat 30
	transitions[Etat::E30][Symbole::plus] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E30][Symbole::moins] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E30][Symbole::multi] = new DeplacerTrans(Etat::E29);
	transitions[Etat::E30][Symbole::divi] = new DeplacerTrans(Etat::E29);

	//Etat 31
	transitions[Etat::E31][Symbole::plus] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E31][Symbole::moins] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E31][Symbole::multi] = new DeplacerTrans(Etat::E29);
	transitions[Etat::E31][Symbole::divi] = new DeplacerTrans(Etat::E29);

	//Etat 33
	transitions[Etat::E33][Symbole::Lc] = new DeplacerTrans(Etat::E38);

	//Etat 34
	transitions[Etat::E34][Symbole::plus] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E34][Symbole::moins] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E34][Symbole::multi] = new DeplacerTrans(Etat::E29);
	transitions[Etat::E34][Symbole::divi] = new DeplacerTrans(Etat::E29);

	//Etat 35
	transitions[Etat::E35][Symbole::plus] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E35][Symbole::moins] = new DeplacerTrans(Etat::E28);
	transitions[Etat::E35][Symbole::multi] = new DeplacerTrans(Etat::E29);
	transitions[Etat::E35][Symbole::divi] = new DeplacerTrans(Etat::E29);
}
