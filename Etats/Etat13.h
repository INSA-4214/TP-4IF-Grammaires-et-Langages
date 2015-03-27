/*
 * Etat13.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT13_H_
#define ETAT13_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat13 : public Etat {

public:

    Etat13();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 13;}


};

#endif /* ETAT13_H_ */
