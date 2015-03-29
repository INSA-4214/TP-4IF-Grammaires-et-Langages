#include "../BlocInstruction.h"
#include "../Instruction.h"
#include "../Symbole.h"
#include "Etat16.h"

Etat16::Etat16() : Etat() { }

bool Etat16::transition(Automate *automate, Symbole * s) {

    BlocInstruction *symb;
    Instruction *I;

    switch ( s->getIdent() ) {
            return true;
        case Symbole::idvar:
        case Symbole::FILEEND :
        case Symbole::w :
        case Symbole::r :

           // Reduction Règle 14 on depile de 3
           for ( int i = 0 ; i < 3 ; i++ ) {
               automate->getPileEtats()->pop();
           }

           automate->getPileSymboles()->pop();
           I = (Instruction*) automate->getPileSymboles()->top();

           automate->getPileSymboles()->pop();
           symb = (BlocInstruction*) automate->getPileSymboles()->top();

           symb->addInstruction(I);

           automate->getPileSymboles()->pop();

           if (!automate->getPileEtats()->top()->transition(automate, symb))
                return false;
           if (!automate->getPileEtats()->top()->transition(automate, s))
                return false;
           return true;
        default:
            return false;
}
return false;
}
