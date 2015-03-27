/*
 * Etat39.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT39_H_
#define ETAT39_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat39 : public Etat {

public:

    Etat39();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 39;}


};

#endif /* ETAT39_H_ */
