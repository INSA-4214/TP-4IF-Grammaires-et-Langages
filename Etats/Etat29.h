/*
 * Etat29.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT29_H_
#define ETAT29_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat29 : public Etat {

public:

    Etat29();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 29;}


};

#endif /* ETAT29_H_ */
