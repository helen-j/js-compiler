#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class ReturnStatement : public Statement
{
private:
	Expression *expr;
public:
	ReturnStatement(Expression *expr) : expr(expr) {
		this->expr = expr;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "ReturnStatement" << endl;
		expr->DumpValue(indent + 1);
	};
};

