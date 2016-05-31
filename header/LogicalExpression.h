#pragma once
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
#include "parser.tab.h"

extern int LastLabel;
using namespace std;


class LogicalExpression : public Expression {
private:
	Expression *lhs, *rhs;
	int op;
public:
	LogicalExpression(Expression* lhs, int op, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->op = op;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "LogicalExpression" << endl;
		lhs->DumpValue(indent + 1);
		this->Indent(indent + 1);
		switch (op)
		{
		case AND:
			cout << "Operator: &&" << endl;
			break;
		case OR:
			cout << "Operator: ||" << endl;
			break;
		}
		rhs->DumpValue(indent + 1);
	};
	int GenCode(FILE* file) {
		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		rrefno = rhs->GenCode(file);
		switch (op)
		{case AND:
			emit(file, "jsValue* r%d = AND(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		case OR:
			emit(file, "jsValue* r%d = OR(r%d,r%d);", LastLabel, lrefno, rrefno);
			break;
		}
		
		return LastLabel++;
	};
};