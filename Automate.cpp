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

	transitions[Etat::E0][Symbole::P] = new AcceptTrans;
}
