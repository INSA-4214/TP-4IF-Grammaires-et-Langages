#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"


class Instruction : public Symbole
{
    public:
        Instruction(Symbole::Id id)
    		:Symbole(id){}
        virtual ~Instruction();
    protected:
    private:
};

#endif // INSTRUCTION_H
