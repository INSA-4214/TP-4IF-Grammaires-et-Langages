#ifndef READ_H
#define READ_H

#include "Symbole.h"
#include "Instruction.h"


class Read : public Instruction
{
    public:
        Read()
    		:Instruction(Symbole::r){}
        Read(Symbole* unSymbole)
        	:Instruction(Symbole::r), idALire(unSymbole){}

        void setIdALire(Symbole* unSymbole) {
        	idALire = unSymbole;
        }

        virtual ~Read();

    private:
        Symbole *idALire;
};

#endif // READ_H
