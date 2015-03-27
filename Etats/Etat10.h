/*
 * Etat10.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT10_H_
#define ETAT10_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat10 : public Etat {

public:

    Etat10();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 10;}


};

#endif /* ETAT10_H_ */
