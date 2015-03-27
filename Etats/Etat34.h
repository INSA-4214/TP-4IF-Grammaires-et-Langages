/*
 * Etat34.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT34_H_
#define ETAT34_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat34 : public Etat {

public:

    Etat34();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 34;}


};

#endif /* ETAT34_H_ */
