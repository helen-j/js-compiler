#pragma once
#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;

class SwitchStatement : public Statement
{
private:
	string Myname;
	Expression* exp;

public:
	SwitchStatement(Expression* exp)
	{
		this->exp = exp;
		this->Myname = "SwitchStatement";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(exp)->DumpValue(indent+1);
	};
	void GenCode(FILE* file) {};
};