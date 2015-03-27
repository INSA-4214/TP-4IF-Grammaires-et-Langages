/*
 * Etat06.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT06_H_
#define ETAT06_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat06 : public Etat {

public:

    Etat06();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 6;}


};

#endif /* ETAT06_H_ */
