/*
 * Etat41.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT41_H_
#define ETAT41_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat41 : public Etat {

public:

    Etat41();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 41;}


};

#endif /* ETAT41_H_ */
