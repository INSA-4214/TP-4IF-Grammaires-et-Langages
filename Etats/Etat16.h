/*
 * Etat16.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT16_H_
#define ETAT16_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat16 : public Etat {

public:

    Etat16();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 16;}


};

#endif /* ETAT16_H_ */
