/*
 * Etat03.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT03_H_
#define ETAT03_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat03 : public Etat {

public:

    Etat03();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 3;}


};

#endif /* ETAT03_H_ */
