#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class ForStatement : public Statement
{
private:
	string Myname;
	Expression* exp1;
	Expression* exp2;
	Expression* exp3;
	Statement* stm1;

public:
	ForStatement(Expression* exp1, Expression* exp2, Expression* exp3, Statement* stm1)
	{
		this->exp1 = exp1;
		this->exp2 = exp2;
		this->exp3 = exp3;
		this->stm1 = stm1;
		this->Myname = "ForStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;

		if (exp1 != nullptr) {
			(exp1)->DumpValue(indent + 1);
		}
		if (exp2 != nullptr) {
			(exp2)->DumpValue(indent + 1);
		}
		if (exp3 != nullptr) {
			(exp3)->DumpValue(indent + 1);
		}
		if (stm1 != nullptr) {
			(stm1)->DumpValue(indent + 1);
		}
	};
};