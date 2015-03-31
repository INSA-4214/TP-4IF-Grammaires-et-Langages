
#include "../Symbole.h"
#include "Etat05.h"
#include "Etat12.h"

Etat05::Etat05() : Etat() { }

bool Etat05::transition(Automate *automate, Symbole * s) {
    BlocDeclaration* symb = new BlocDeclaration;
    switch ( s->getIdent() ) {
        case Symbole::pv:
        automate->decalage(s, new Etat12());
           return true;
        default:
        automate->decalage(symb, new Etat12());
        automate->erreurSyntax("symbole", ";");
            return false;
}
return false;
}
