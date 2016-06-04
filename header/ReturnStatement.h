#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;
extern int LastLabel;

class ReturnStatement : public Statement
{
private:
	Expression *exp;
	string Myname;

public:
	ReturnStatement(Expression *expr) : exp(exp) {
		this->exp = expr;
		this->Myname = "ReturnStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		if (exp!=nullptr)
			exp->DumpValue(indent + 1);
	};
	void GenCode(FILE* file) {
		int refno;
		refno = exp->GenCode(file);
		emit(file, "return (GetValue(r%d)->ToBool()->value);", LastLabel - 1);
	
	};
};

