/*
 * Etat32.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT32_H_
#define ETAT32_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat32 : public Etat {

public:

    Etat32();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 32;}


};

#endif /* ETAT32_H_ */
