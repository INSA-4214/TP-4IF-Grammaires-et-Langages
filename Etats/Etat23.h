/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT23_H_
#define ETAT23_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat23 : public Etat {

public:

    Etat23();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 23;}


};

#endif /* ETAT023_H_ */
