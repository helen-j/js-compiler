#pragma once
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class NumericLiteralExpression : public Expression
{
private:
	double value;
public:
	NumericLiteralExpression(double value)
	{
		this->value = value;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "NumericLiteral" << endl;
		this->Indent(indent + 1);
		cout << "{" << endl;
		this->Indent(indent + 2);
		cout << value << endl;
		this->Indent(indent + 1);
		cout << "}" << endl;
	};
};
