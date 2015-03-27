/*
 * Etat35.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT35_H_
#define ETAT35_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat35 : public Etat {

public:

    Etat35();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 35;}


};

#endif /* ETAT35_H_ */
