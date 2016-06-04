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

		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		switch (Operator)
		{
		case '+':
			emit(file, "jsValue* r%d = unaryPlus(r%d,r%d);", LastLabel, lrefno);
			break;
		case '-':
			emit(file, "jsValue* r%d = Greaterthan(r%d,r%d);", LastLabel, lrefno);
			break;
		case INC:
			emit(file, "jsValue* r%d = Increment(r%d,r%d);", LastLabel, lrefno);
			break;
		case DEC:
			emit(file, "jsValue* r%d = Decrement(r%d,r%d);", LastLabel, lrefno);
			break;
		}
		return LastLabel++;
	}
};
