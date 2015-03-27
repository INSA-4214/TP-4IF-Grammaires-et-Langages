/*
 * Etat25.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT25_H_
#define ETAT25_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat25 : public Etat {

public:

    Etat25();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 25;}


};

#endif /* ETAT25_H_ */
