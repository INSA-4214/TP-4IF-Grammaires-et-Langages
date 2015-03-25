/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT01_H_
#define ETAT01_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat01 : public Etat {

public:

    Etat01();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 1;}


};

#endif /* ETAT01_H_ */
