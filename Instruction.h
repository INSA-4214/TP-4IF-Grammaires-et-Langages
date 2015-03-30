#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"


class Instruction : public Symbole
{
    public:
        Instruction()
    		:Symbole(Symbole::I){}
        virtual ~Instruction();
        virtual void print() {};
    protected:
    private:
};

#endif // INSTRUCTION_H
