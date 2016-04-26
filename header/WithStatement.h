#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif

#ifndef Expression_H_
#include "Expression.h"
#endif
class WithStatement : public Statement
	
{
private:
	Expression *expr;
	Statement *stm;
public:
	WithStatement(Expression *expr, Statement *stm) : expr(expr), stm(stm) {
	};
	void DumpValue(int indent)
	{
		this->Indent(indent);
		cout << "WithStatement" << endl;
		expr->DumpValue(indent + 1);
		stm->DumpValue(indent + 1);
	}
};
