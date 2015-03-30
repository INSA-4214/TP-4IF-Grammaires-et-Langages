/*
 * Etat42.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT42_H_
#define ETA42_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat42 : public Etat {

public:

    Etat42();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 42;}


};

#endif /* ETAT42_H_ */
