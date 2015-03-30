/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT18_H_
#define ETAT18_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat18 : public Etat {

public:

    Etat18();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 18;}


};

#endif /* ETAT18_H_ */
