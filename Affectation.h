#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expr.h"

class Affectation : public Instruction
{
    public:
        Affectation():
        	Instruction(Symbole::aff){}
        virtual ~Affectation();

        void setIdVar(std::string unIdVar) {
        	m_idVar = unIdVar;
        }

        void setExpr(Expr* uneExpr) {
        	e = uneExpr;
        }

    private:
        std::string m_idVar;
        Expr * e;
};

#endif // AFFECTATION_H
