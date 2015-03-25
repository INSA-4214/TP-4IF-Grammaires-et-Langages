/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT00_H_
#define ETAT00_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat00 : public Etat {

public:

    Etat00();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 0;}


};

#endif /* ETAT00_H_ */
