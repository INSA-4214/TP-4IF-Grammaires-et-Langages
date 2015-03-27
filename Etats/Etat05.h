/*
 * Etat05.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT05_H_
#define ETAT05_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat05 : public Etat {

public:

    Etat05();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 5;}


};

#endif /* ETAT05_H_ */
