#pragma once
#include <string>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class StringLiteral : public Expression
{
private:
	string value;
public:
	StringLiteral(string value)
	{
		//Remove Quotations
		value=value.erase(0, 1);
		value=value.erase(value.size()-1, value.size());
		//Set value
		this->value = value;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "StringLiteral" << endl;
		this->Indent(indent + 1);
		cout << "{" << endl;
		this->Indent(indent + 2);
		cout << value << endl;
		this->Indent(indent + 1);
		cout << "}" << endl;
	};
	int GenCode(FILE* file) {
		emit(file, "jsValue* r%d = new jsString(\"%s\");", LastLabel, value.c_str());
		return LastLabel++;
	};
};
