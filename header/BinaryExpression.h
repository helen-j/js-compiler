#pragma once
#include <iostream>
#ifndef Expression_H_
#include "Expression.h"
#include "parser.tab.h"
#endif
extern int LastLabel;
using namespace std;


class BinaryExpression : public Expression {
private:
	int Operator;
	Expression *lhs, *rhs;

public:
	int LEFTSHIFT = 10;
	BinaryExpression(Expression* lhs, int Operator, Expression* rhs) {

		cout << Operator << endl;


		this->lhs = lhs;
		this->Operator = Operator;
		this->rhs = rhs;
	
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "BinaryExpression" << endl;
		lhs->DumpValue(indent + 1);
		this->Indent(indent + 1);
		switch (Operator)
		{
		case LEFTSHIFT:
			cout << "Operator: <<" << endl;
			break;
		case RIGHTSHIFT:
			cout << "Operator: >>" << endl;
			break;
		case LOGICRIGHTSHIFT:
			cout << "Operator: >>>" << endl;
			break;
		}
		
		rhs->DumpValue(indent + 1);
	};
	int GenCode(FILE* file) {

		int lrefno, rrefno;
		lrefno = lhs->GenCode(file);
		rrefno = rhs->GenCode(file);
		switch (Operator)//buzhidao yao bu yao 
		{
		case LEFTSHIFT:
			emit(file, "jsValue* r%d = LEFTSHIFT(r%d,r%d);", LastLabel, lrefno);
			break;
		case RIGHTSHIFT:
			emit(file, "jsValue* r%d = RIGHTSHIFT(r%d,r%d);", LastLabel, lrefno);
			break;
		case LOGICRIGHTSHIFT:
			emit(file, "jsValue* r%d = LOGICRIGHTSHIFT(r%d,r%d);", LastLabel, lrefno);
			break;

		}
		return LastLabel++;

	};
};