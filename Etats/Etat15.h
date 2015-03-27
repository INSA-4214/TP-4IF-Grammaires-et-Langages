/*
 * Etat15.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT15_H_
#define ETAT15_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat15 : public Etat {

public:

    Etat15();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 15;}


};

#endif /* ETAT15_H_ */
