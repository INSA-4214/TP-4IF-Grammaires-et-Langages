#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"
#include <map>

using namespace std;

class Instruction : public Symbole
{
    public:

        Instruction()
    		:Symbole(Symbole::I){}

        virtual ~Instruction();

        virtual void exec(map<string, pair<double, bool> > *table)=0;


        virtual void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table)=0;

        virtual void print() {};

    protected:
    private:
};

#endif // INSTRUCTION_H
