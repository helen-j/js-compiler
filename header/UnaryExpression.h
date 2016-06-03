#pragma once
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#include "parser.tab.h"
#endif
extern int LastLabel;
using namespace std;


class UnaryExpression : public Expression {
private:
	int Operator;
	Expression *lhs;
public:
	UnaryExpression(int Operator, Expression* lhs) {

		this->lhs = lhs;
		this->Operator = Operator;

	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "UnaryExpression" << endl;
		lhs->DumpValue(indent + 1);
		this->Indent(indent + 1);
		switch (Operator)
		{
		case '+': 
			cout << "Operator: +" << endl;
			break;
		case '-':
			cout << "Operator: -" << endl;
			break;
		case INC:
			cout << "Operator: ++" << endl;
			break;
		case DEC:
			cout << "Operator: --" << endl;
			break;
		}
	};
	int GenCode(FILE* file) {
		return LastLabel;
	};
};
