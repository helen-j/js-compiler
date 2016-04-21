#pragma once
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class IntegerLiteralExpression : public Expression
{
private:
	int value;
public:
	IntegerLiteralExpression(int value)
	{
		this->value = value;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "IntegerLiteral" << endl;
		this->Indent(indent + 1);
		cout << "{" << endl;
		this->Indent(indent + 2);
		cout << value << endl;
		this->Indent(indent + 1);
		cout << "}" << endl;
	};
};
