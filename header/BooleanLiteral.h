#pragma once
#include <string>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class BooleanLiteral : public Expression
{
private:
	string Myname;
	bool value;
public:
	BooleanLiteral(bool value)
	{
		this->value = value;
		this->Myname = "BooleanLiteral";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		this->Indent(indent + 1);
		cout << "{" << endl;
		this->Indent(indent + 2);
		cout << value << endl;
		this->Indent(indent + 1);
		cout << "}" << endl;
	};
	int GenCode(FILE* file) {
		return 0;
	};
};
