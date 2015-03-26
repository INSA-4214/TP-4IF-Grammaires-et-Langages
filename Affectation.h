#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expr.h"

class Affectation : public Instruction
{
    public:
        Affectation();
        virtual ~Affectation();
    protected:
    private:
        std::string m_idVar;
        Expr * e;
};

#endif // AFFECTATION_H
