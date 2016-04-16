#pragma once
#include <string>
#include <iostream>
#include "Expression.h"
using namespace std;

class IdentifierExpression : public Expression
{
private:
	string name;
	string Myname;
public:
	IdentifierExpression(string name)
	{
		this->name = name;
		this->Myname = "IdentifierName";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		this->Indent(indent + 2);
		cout << "{" << endl;
		this->Indent(indent + 3);
		cout << name << endl;
		this->Indent(indent + 2);
		cout << "}" << endl;
	};
};