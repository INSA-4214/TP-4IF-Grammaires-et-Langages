/*
 * Etat28.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT28_H_
#define ETAT28_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat28 : public Etat {

public:

    Etat28();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 28;}


};

#endif /* ETAT28_H_ */
