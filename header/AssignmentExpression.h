#pragma once
#include <string>
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

extern int LastLabel;

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
		lhs->DumpValue(indent + 1);
		rhs->DumpValue(indent + 1);
	};
	int GenCode(FILE* file) {
		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		rrefno = rhs->GenCode(file);
		emit(file, "jsValue* r%d = Assign(r%d,r%d);", LastLabel,lrefno,rrefno);
		return LastLabel++;
	}; 
};