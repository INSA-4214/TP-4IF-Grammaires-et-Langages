/*
 * Etat01.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT17_H_
#define ETAT17_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat17 : public Etat {

public:

    Etat17();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 17;}


};

#endif /* ETAT17_H_ */
