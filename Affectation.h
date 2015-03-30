#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expr.h"

class Affectation : public Instruction
{
    public:
        Affectation():
        	Instruction(){}
        virtual ~Affectation();

        void setIdVar(std::string unIdVar) {
        	m_idVar = unIdVar;
        }

        void setExpr(Expr* uneExpr) {
        	e = uneExpr;
        }
        void exec(map<string, pair<double, bool> > *table);
    private:
        std::string m_idVar;
        Expr * e;
};

#endif // AFFECTATION_H
