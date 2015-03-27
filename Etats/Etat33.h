/*
 * Etat33.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT33_H_
#define ETAT33_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat33 : public Etat {

public:

    Etat33();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 33;}


};

#endif /* ETAT33_H_ */
