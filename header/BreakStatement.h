#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class BreakStatement : public Statement
{
private:
	Expression *expr;
public:
	BreakStatement(Expression *expr) : expr(expr) {
		this->expr = expr;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "BreakStatement" << endl;
		if (expr != nullptr)
			expr->DumpValue(indent + 1);
	};
	void GenCode(FILE* file) {};
};

