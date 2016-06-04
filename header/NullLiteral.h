#pragma once
#include <string>
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;


class NullLiteral : public Expression
{
private:
	double value;
public:
	NullLiteral(double value)
	{
		this->value = 0;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "NullLiteral" << endl;
		this->Indent(indent + 1);
		cout << "{" << endl;
		this->Indent(indent + 2);
		cout << value << endl;
		this->Indent(indent + 1);
		cout << "}" << endl;
	};
	
	int GenCode(FILE* file) {
		emit(file, "jsValue* r%d = new jsNumber(%i);", LastLabel, value);
		return LastLabel++;
	};

};
