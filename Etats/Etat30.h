/*
 * Etat30.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT30_H_
#define ETAT30_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat30 : public Etat {

public:

    Etat30();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 30;}


};

#endif /* ETAT30_H_ */
