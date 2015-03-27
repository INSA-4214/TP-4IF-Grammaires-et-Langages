/*
 * Etat27.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT27_H_
#define ETAT27_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat27 : public Etat {

public:

    Etat27();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 27;}


};

#endif /* ETAT27_H_ */
