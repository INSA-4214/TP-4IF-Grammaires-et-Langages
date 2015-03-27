/*
 * Etat04.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT04_H_
#define ETAT04_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat04 : public Etat {

public:

    Etat04();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 4;}


};

#endif /* ETAT04_H_ */
