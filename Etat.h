/*
 * Etat.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef ETAT_H_
#define ETAT_H_

#include <string>
#include "Symbole.h"
class Automate;

class Etat {

public:

Etat() { }
virtual bool transition(Automate *automate, Symbole * s) = 0;
virtual int numEtat() = 0;
};

#endif /* ETAT_H_ */
