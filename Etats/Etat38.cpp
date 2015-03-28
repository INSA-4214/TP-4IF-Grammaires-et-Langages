#include "../Symbole.h"
#include "Etat38.h"
#include "Etat39.h"


Etat38::Etat38() : Etat() { }

bool Etat38::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::D);
    switch ( s->getIdent() ) {
        case Symbole::virg :
        automate->decalage(s, new Etat39());
           return true;
        case Symbole::pv:
        case Symbole::FILEEND :

// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
            for ( int i = 0 ; i < 5 ; i++ ) {
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
