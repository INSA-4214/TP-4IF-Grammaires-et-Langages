/*
 * Etat08.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT08_H_
#define ETAT08_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat08 : public Etat {

public:

    Etat08();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 8;}


};

#endif /* ETAT08_H_ */
