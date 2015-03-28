
#include "../Symbole.h"
#include "Etat02.h"
#include "Etat06.h"
#include "Etat07.h"
#include "Etat05.h"
#include "Etat04.h"

#include <stdio.h>

using namespace std;

Etat02::Etat02() : Etat() { }

bool Etat02::transition(Automate *automate, Symbole * s) {
     cout << "Symbole courant : " << endl;
  Symbole symb = Symbole(Symbole::Bi);
    switch ( s->getIdent() ) {
        case Symbole::var:
        automate->decalage(s, new Etat06());
           return true;
        case Symbole::D:
            automate->decalage(s, new Etat05());
            return true;
        case Symbole::Bi:
            automate->decalage(s, new Etat04());
            return true;
        case Symbole::cst:
          automate->decalage(s, new Etat07());
            return true;
        case Symbole::idvar:
        case Symbole::w :
        case Symbole::r :
        case Symbole::FILEEND:
// Reduction Règle 15 - 0 Level On pop Bi car Bi->.

           if (!automate->getPileEtats()->top()->transition(automate, &symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
            return false;
    }
return false;
}
