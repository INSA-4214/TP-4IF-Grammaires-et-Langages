#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expr.h"
#include <iostream>

class Affectation : public Instruction
{
    public:
	using Instruction::print;
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

        void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
        void print();

    private:
        std::string m_idVar;
        Expr * e;
};

#endif // AFFECTATION_H
