#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;

class WhileStatement : public Statement
{
private:
	string Myname;
	Expression* exp;
	Statement* stm1;

public:
	WhileStatement(Expression* exp, Statement* stm1)
	{
		this->exp = exp;
		this->stm1 = stm1;
		this->Myname = "WhileStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(exp)->DumpValue(indent+1);
		(stm1)->DumpValue(indent+1);
	};
};