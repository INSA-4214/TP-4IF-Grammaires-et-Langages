/*
 * Etat31.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT31_H_
#define ETAT31_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat31 : public Etat {

public:

    Etat31();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 31;}


};

#endif /* ETAT31_H_ */
