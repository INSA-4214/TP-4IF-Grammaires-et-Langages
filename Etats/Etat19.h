/*
 * Etat19.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT19_H_
#define ETAT19_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat19 : public Etat {

public:

    Etat19();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 19;}


};

#endif /* ETAT19_H_ */
