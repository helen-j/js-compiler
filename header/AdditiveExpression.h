#pragma once
#include <string>
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class AdditiveExpression : public Expression {
private:
	string Myname;
	Expression *lhs, *rhs;
	char *op;
public:
	AdditiveExpression(char* op, Expression* lhs, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->Myname = "AdditiveExpression";
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
		if (strcmp(op, "+") == 0) 
			emit(file, "jsValue* r%d = Plus(r%d,r%d);", LastLabel, lrefno, rrefno);
		else if (strcmp(op, "-") == 0)
			emit(file, "jsValue* r%d = Minus(r%d,r%d);", LastLabel, lrefno, rrefno);
		
		return LastLabel++;
	};
};