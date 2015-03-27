/*
 * Etat33.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT37_H_
#define ETAT37_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat37 : public Etat {

public:

    Etat37();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 37;}


};

#endif /* ETAT37_H_ */
