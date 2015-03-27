/*
 * Etat12.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT12_H_
#define ETAT12_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat12 : public Etat {

public:

    Etat12();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 12;}


};

#endif /* ETAT12_H_ */
