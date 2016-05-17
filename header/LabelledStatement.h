#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class LabelledStatement : public Statement
{
private:
	Expression *expr1;
	Statement *stm1;
public:
	LabelledStatement(Expression *expr1,Statement *stm1){
		this->expr1 = expr1;
		this->stm1 = stm1;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "LabelledStatement" << endl;
		expr->DumpValue(indent + 1);
	};
};

