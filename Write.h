#ifndef WRITE_H
#define WRITE_H

#include "Instruction.h"
#include "Expr.h"

class Write : public Instruction
{
    public:
		Write()
    		:Instruction(){}
		Write(Expr* uneExpr)
			:Instruction(), e(uneExpr){}

		void setExpr(Expr* uneExpr) {
			e = uneExpr;
		}
		
        void staticAnalysis(std::map<std::string, std::pair<bool, bool> > *table);
		void print();
        virtual ~Write();

    private:
        Expr * e;
};

#endif // WRITE_H
