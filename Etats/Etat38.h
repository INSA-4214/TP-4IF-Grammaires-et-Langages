/*
 * Etat38.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT38_H_
#define ETAT38_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat38 : public Etat {

public:

    Etat38();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 38;}


};

#endif /* ETAT38_H_ */
