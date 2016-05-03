#pragma once
#include <string>
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class BinaryExpression : public Expression {
private:
	string MyName;
	string *Operator;
	Expression *lhs, *rhs;
public:
	BinaryExpression(Expression* lhs, string* Operator, Expression* rhs) {

		cout << Operator << endl;


		this->lhs = lhs;
		this->Operator = Operator;
		this->rhs = rhs;
		this->MyName = "BinaryExpression";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << MyName << endl;
		lhs->DumpValue(indent + 1);
		cout << Operator << endl;
		rhs->DumpValue(indent + 1);
	};

};