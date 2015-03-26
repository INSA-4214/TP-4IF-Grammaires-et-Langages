#ifndef WRITE_H
#define WRITE_H

#include "Instruction.h"
#include "Expr.h"

class Write : public Instruction
{
    public:
        Write();
        virtual ~Write();
    protected:
    private:
        Expr * e;
};

#endif // WRITE_H
