/*
 * Etat20.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT20_H_
#define ETAT20_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat20 : public Etat {

public:

    Etat20();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 20;}


};

#endif /* ETAT20_H_ */
