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
			emit(file, "jsBoolean* r%d = AbstractEquality(GetValue(r%d),GetValue(r%d));", LastLabel, lrefno, rrefno);
			break;
		case NEV:
			emit(file, "jsBoolean* r%d = AbstractEquality(GetValue(r%d),GetValue(r%d));", LastLabel, lrefno, rrefno);
			emit(file, "jsBoolean* r%d = new jsBoolean(!(r%d)->value);", LastLabel + 1, LastLabel);
			return LastLabel = LastLabel + 2;
		case NEVT:
			emit(file, "jsBoolean* r%d = StricttEquality(GetValue(r%d),GetValue(r%d));", LastLabel, lrefno, rrefno);
			emit(file, "jsBoolean* r%d = new jsBoolean(!(r%d)->value);", LastLabel + 1, LastLabel);
			return LastLabel=LastLabel+2;
		case ETT:
			emit(file, "jsBoolean* r%d = StrictEquality(GetValue(r%d),GetValue(r%d));", LastLabel, lrefno, rrefno);
			break;
		}
		return LastLabel++;
	};
};