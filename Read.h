#ifndef READ_H
#define READ_H

#include "Instruction.h"


class Read : public Instruction
{
    public:
        Read();
        virtual ~Read();
    protected:
    private:
        std::string m_idVar;
};

#endif // READ_H
