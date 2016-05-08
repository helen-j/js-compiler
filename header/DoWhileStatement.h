#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;

class DoWhileStatement : public Statement
{
private:
	string Myname;
	Statement* stm1;
	Expression* exp;


public:
	DoWhileStatement(Statement* stm1,Expression* exp)
	{
		this->stm1 = stm1;
		this->exp = exp;
		this->Myname = "DoWhileStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(stm1)->DumpValue(indent+1);
		(exp)->DumpValue(indent+1);
		}
	};
