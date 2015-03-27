/*
 * Etat014.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT14_H_
#define ETAT14_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat14 : public Etat {

public:

    Etat14();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 14;}


};

#endif /* ETAT14_H_ */
