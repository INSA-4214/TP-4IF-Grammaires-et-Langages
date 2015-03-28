
#include "../Symbole.h"
#include "Etat04.h"
#include "Etat11.h"
#include "Etat10.h"
#include "Etat08.h"
#include "Etat09.h"

#include <stdio.h>

using namespace std;

Etat04::Etat04() : Etat() { }

bool Etat04::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::P);
    switch ( s->getIdent() ) {
        case Symbole::idvar:
        automate->decalage(s, new Etat11());
        cout << "Symbole pile : " <<  automate->getPileSymboles()->top()->getStr() << endl;
           return true;
        case Symbole::w:
          automate->decalage(s, new Etat10());
            return true;
        case Symbole::r:
            automate->decalage(s, new Etat08());
            return true;
        case Symbole::I:
            automate->decalage(s, new Etat09());
            return true;
        case Symbole::FILEEND :
           for ( int i = 0 ; i < 2 ; i++ ) {
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
            }
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
