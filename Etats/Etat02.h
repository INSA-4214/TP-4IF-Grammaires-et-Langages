/*
 * Etat02.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT02_H_
#define ETAT02_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat02 : public Etat {

public:

    Etat02();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 2;}


};

#endif /* ETAT02_H_ */
