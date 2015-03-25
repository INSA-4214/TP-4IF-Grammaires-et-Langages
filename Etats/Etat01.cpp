
#include "../Symbole.h"
#include "Etat01.h"

Etat01::Etat01() : Etat() { }

bool Etat01::transition(Automate *automate, Symbole * s) {
   // Symbole symb = Symbole(Bd);
  /*  switch ( s->getIdent() ) {
        case TokenType::I:
            automaton->decalage(t, new E2());
            return true;
        case TokenType::VAR:
            automaton->decalage(t, new E21());
            return true;
        case TokenType::CONST:
            automaton->decalage(t, new E27());
            return true;
        case TokenType::ID:
        case TokenType::VAL:
        case TokenType::V:
        case TokenType::PV:
        case TokenType::AFF:
        case TokenType::EQ:
        case TokenType::ENDOFFILE:
        case TokenType::WRITE:
        case TokenType::READ:
            // Reduction N°12 - 0 Level Pop - "I->."
            symb = Symbole(TokenType::I);
            if (!automaton->getStackStates()->top()->transition(
            automaton, &symb)) return false;
            if (!automaton->getStackStates()->top()->transition(
            automaton, t)) return false;
            return true;
        default:
            return false;
    }*/
    return false;
}
