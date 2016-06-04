#pragma once
#include <string>
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif

extern int LastLabel;
using namespace std;


class RelationalExpression : public Expression {
private:
	string Myname;
	Expression *lhs, *rhs;
	int op;
public:
	RelationalExpression(Expression* lhs, int op, Expression* rhs) {
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
	int GenCode(FILE* file) {
		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		rrefno = rhs->GenCode(file);
		switch (op)
		{
		case '<':
			emit(file, "jsValue* r%d = Lessthan(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case '>':
			emit(file, "jsValue* r%d = GreaterThan(r%d,r%d);", LastLabel, lrefno,rrefno);
			break;
		case LE:
			emit(file, "jsValue* r%d = LessThanEqual(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case GE:
			emit(file, "jsValue* r%d = GreaterThanEqual(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case INSTANCEOF:
			break;
		case IN:
			break;
		}
		return LastLabel++;
	};
};