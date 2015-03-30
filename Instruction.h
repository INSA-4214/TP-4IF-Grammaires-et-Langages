#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"


class Instruction : public Symbole
{
    public:
        Instruction()
    		:Symbole(Symbole::I){}
        virtual ~Instruction();
        void printI();
        virtual void exec(map<string, pair<double, bool> > *table);
    protected:
    private:
};

#endif // INSTRUCTION_H
