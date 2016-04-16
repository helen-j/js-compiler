#pragma once
#include <string>
#include <iostream>
#include "Expression.h"
using namespace std;


class AssignmentExpression : public Expression {
private:
	string Myname;
	Expression *lhs, *rhs;
public:
	AssignmentExpression(Expression* lhs, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->Myname = "AssignmentExpression";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		lhs->DumpValue(indent + 2);
		rhs->DumpValue(indent + 2);
	};
};