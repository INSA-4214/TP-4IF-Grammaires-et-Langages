#ifndef WRITE_H
#define WRITE_H

#include "Instruction.h"
#include "Expr.h"

class Write : public Instruction
{
    public:
		Write()
    		:Instruction(Symbole::w){}
		Write(Expr* uneExpr)
			:Instruction(Symbole::w), e(uneExpr){}

		void setExpr(Expr* uneExpr) {
			e = uneExpr;
		}

        virtual ~Write();

    private:
        Expr * e;
};

#endif // WRITE_H
