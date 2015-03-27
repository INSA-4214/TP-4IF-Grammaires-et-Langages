/*
 * Etat07.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT07_H_
#define ETAT07_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat07 : public Etat {

public:

    Etat07();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 7;}


};

#endif /* ETAT07_H_ */
