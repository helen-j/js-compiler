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
	int DoWhileLabel;

public:
	static int DoWhileObejct;
	DoWhileStatement(Statement* stm1,Expression* exp)
	{
		this->stm1 = stm1;
		this->exp = exp;
		this->Myname = "DoWhileStatement";
		DoWhileObejct++;
		DoWhileLabel = DoWhileObejct;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		(stm1)->DumpValue(indent+1);
		(exp)->DumpValue(indent+1);
		}
	void GenCode(FILE* file) {
		int refno;
		emit(file, "DoWhileLabel%d:", DoWhileLabel);
		refno = exp->GenCode(file);
		stm1->GenCode(file);
		emit(file, "if (GetValue(r%d)->ToBool()->value) {", LastLabel - 1);
		emit(file, "goto DoWhileLabel%d;", DoWhileLabel);
		emit(file, "}");
	};
	};
