#pragma once
#include <string>
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class RelationalExpression : public Expression {
private:
	string Myname;
	Expression *lhs, *rhs;
	char *op;
public:
	RelationalExpression(Expression* lhs, char* op, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->Myname = "RelationalExpression";
		this->op = op;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		lhs->DumpValue(indent + 1);
		rhs->DumpValue(indent + 1);
	};
};