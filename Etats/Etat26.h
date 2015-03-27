/*
 * Etat26.h
 *
 *  Created on: 8 mars 2015
 *
 */

#ifndef ETAT26_H_
#define ETAT26_H_

#include <string>
#include "../Symbole.h"
#include "../Etat.h"
#include "../Automate.h"

class Etat26 : public Etat {

public:

    Etat26();
    bool transition(Automate *automate, Symbole * s);
    inline int numEtat() {return 26;}


};

#endif /* ETAT26_H_ */
