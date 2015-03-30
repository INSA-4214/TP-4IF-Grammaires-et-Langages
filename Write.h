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
        void exec(map<string, pair<double, bool> > *table);
        virtual ~Write();

    private:
        Expr * e;
};

#endif // WRITE_H
