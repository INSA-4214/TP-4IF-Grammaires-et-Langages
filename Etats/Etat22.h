/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT22_H_
#define ETAT22_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat22 : public Etat {

public:

    Etat22();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 22;}


};

#endif /* ETAT22_H_ */
