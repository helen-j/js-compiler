#pragma once
#include <string>
#ifndef Statement_H_
#include "Statement.h"
#endif
using namespace std;
extern int LastLabel;

class WhileStatement : public Statement
{
private:
	string Myname;
	Expression* exp;
	Statement* stm1;
	int WhileLabel;

public:
	static int WhileObject;
	WhileStatement(Expression* exp, Statement* stm1)
	{
		this->exp = exp;
		this->stm1 = stm1;
		this->Myname = "WhileStatement";
		WhileObject++;
		WhileLabel = WhileObject;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(exp)->DumpValue(indent+1);
		(stm1)->DumpValue(indent+1);
	};
	void GenCode(FILE* file) {
		int refno;
		emit(file, "WhileLabel%d:", WhileLabel);
		refno = exp->GenCode(file);
		emit(file, "if (GetValue(r%d)->ToBool()->value) {", LastLabel - 1);
		stm1->GenCode(file);
		emit(file, "goto WhileLabel%d;", WhileLabel);
		emit(file, "}");
	};
};