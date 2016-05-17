#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;

class ForInStatement : public Statement
{
private:
	string Myname;
	Expression* exp1;
	Expression* exp2;
	Statement* stm1;

public:
	ForInStatement(Expression* exp1, Expression* exp2, Statement* stm1)
	{
		this->exp1 = exp1;
		this->exp2 = exp2;
		this->stm1 = stm1;
		this->Myname = "ForInStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(exp1)->DumpValue(indent + 1);
		(exp2)->DumpValue(indent + 1);
		(stm1)->DumpValue(indent + 1);
	};

};