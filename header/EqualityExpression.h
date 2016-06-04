#pragma once
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
#include "parser.tab.h"

extern int LastLabel;
using namespace std;


class EqualityExpression : public Expression {
private:
	Expression *lhs, *rhs;
	int op;
public:
	EqualityExpression(Expression* lhs, int op, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->op = op;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "EqualityExpression" << endl;
		lhs->DumpValue(indent + 1);
		this->Indent(indent + 1);
		switch (op)
		{
		case ET:
			cout << "Operator: ==" << endl;
			break;
		case NEV:
			cout << "Operator: !=" << endl;
			break;
		case NEVT:
			cout << "Operator: !==" << endl;
			break;
		case ETT:
			cout << "Operator: ===" << endl;
			break;
		}
		rhs->DumpValue(indent + 1);
	};
	int GenCode(FILE* file) {
		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		rrefno = rhs->GenCode(file);
		switch (op)
		{case ET:
			emit(file, "jsValue* r%d = Equality(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case NEV:
			emit(file, "jsValue* r%d = NotEquality(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case NEVT:
			emit(file, "jsValue* r%d = StrictEquality(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case ETT:
			emit(file, "jsValue* r%d = NotStrictEquality(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		}
		return LastLabel++;
	};
};