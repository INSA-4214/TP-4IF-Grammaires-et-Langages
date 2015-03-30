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

        virtual void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table)=0;

    protected:
    private:
};

#endif // INSTRUCTION_H
