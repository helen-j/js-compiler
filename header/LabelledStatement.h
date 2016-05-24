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
	Expression *exp;
	Statement *stm1;
public:
	LabelledStatement(Expression *exp,Statement *stm1){
		this->exp = exp;
		this->stm1 = stm1;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "LabelledStatement" << endl;
		exp->DumpValue(indent + 1);
	};
	void GenCode(FILE* file) {};
};

