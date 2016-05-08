#pragma once
#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;

class IfStatement : public Statement
{
private:
	string Myname;
	Expression* exp;
	Statement* stm1;
	Statement* stm2;

public:
	IfStatement(Expression* exp, Statement* stm1, Statement* stm2)
	{
		this->exp = exp;
		this->stm1 = stm1;
		this->stm2 = stm2;
		this->Myname = "IfStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(exp)->DumpValue(indent+1);
		(stm1)->DumpValue(indent+1);
		if (stm2 != nullptr) {
			(stm2)->DumpValue(indent+1);
		}
	};
};