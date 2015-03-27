/*
 * Etat36.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT36_H_
#define ETAT36_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat36 : public Etat {

public:

    Etat36();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 36;}


};

#endif /* ETAT36_H_ */
