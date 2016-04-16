#pragma once
#include <string>
#include <iostream>
#include "Expression.h"
using namespace std;


class IntegerLiteralExpression : public Expression
{
private:
	int value;
	string Myname;
public:
	IntegerLiteralExpression(int value)
	{
		this->value = value;
		this->Myname = "IntegerLiteral";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		this->Indent(indent + 2);
		cout << "{" << endl;
		this->Indent(indent + 3);
		cout << value << endl;
		this->Indent(indent + 2);
		cout << "}" << endl;
	};
};
