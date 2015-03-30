#ifndef READ_H
#define READ_H

#include "Symbole.h"
#include "Instruction.h"


class Read : public Instruction
{
    public:
        Read()
    		:Instruction(){}
        Read(std::string unString)
        	:Instruction(), idALire(unString){}

        void setIdALire(std::string unString) {
        	idALire = unString;
        }

        std::string getIdALire() {

        	return idALire;
        };
        void print();
        void exec(map<string, pair<double, bool> > *table);
        void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);

        virtual ~Read();

    private:
        std::string idALire;
};

#endif // READ_H
