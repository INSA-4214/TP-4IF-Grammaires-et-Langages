/*
 * Etat11.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT11_H_
#define ETAT11_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat11 : public Etat {

public:

    Etat11();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 11;}


};

#endif /* ETAT11_H_ */
