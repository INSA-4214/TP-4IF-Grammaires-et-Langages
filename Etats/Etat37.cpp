#include "../Symbole.h"
#include "../Declaration.h"
#include "Etat37.h"
#include <set>

Etat37::Etat37() : Etat() { }

bool Etat37::transition(Automate *automate, Symbole * s) {
    std::set<Symbole*> mesidvar;
    Symbole* lastidvar = automate->getPileSymboles()->top();
    Lv symb(mesidvar);

    switch ( s->getIdent() ) {
        case Symbole::pv:
        case Symbole::virg :
        case Symbole::FILEEND :
// Reduction Règle 13 - 0 Level On pop Bd car Bd->.
            for ( int i = 0 ; i < 2 ; i++ ) {
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
            }
            symb = Lv(  dynamic_cast<Lv*>   (automate->getPileSymboles()->top())   ->Lv::getSetidvar());
            symb.addidvar(lastidvar);
               automate->getPileSymboles()->pop();
               automate->getPileEtats()->pop();
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
