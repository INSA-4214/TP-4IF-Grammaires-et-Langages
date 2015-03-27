/*
 * Etat21.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT21_H_
#define ETAT21_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat21 : public Etat {

public:

    Etat21();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 21;}


};

#endif /* ETAT21_H_ */
