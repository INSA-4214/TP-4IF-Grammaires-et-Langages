/*
 * Etat09.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT09_H_
#define ETAT09_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat09 : public Etat {

public:

    Etat09();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 9;}


};

#endif /* ETAT09_H_ */
