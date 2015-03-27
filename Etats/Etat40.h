/*
 * Etat40.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT40_H_
#define ETAT40_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat40 : public Etat {

public:

    Etat40();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 40;}


};

#endif /* ETAT40_H_ */
