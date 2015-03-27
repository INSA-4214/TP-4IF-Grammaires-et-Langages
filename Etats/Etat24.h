/*
 * Etat24.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT24_H_
#define ETAT24_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat24 : public Etat {

public:

    Etat24();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 24;}


};

#endif /* ETAT24_H_ */
