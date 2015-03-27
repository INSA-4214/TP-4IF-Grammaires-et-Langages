
#include "../Symbole.h"
#include "Etat01.h"

Etat01::Etat01() : Etat() { }

bool Etat01::transition(Automate *automate, Symbole * s) {
    Symbole symb = Symbole(Symbole::Bd);
    switch ( s->getIdent() ) {
        case Symbole::FILEEND:
            automate->setAccepter(true);
            return true;
        default:
            return false;
    }
return false;
}
