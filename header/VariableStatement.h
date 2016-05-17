#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif

#ifndef Expression_H_
#include "Expression.h"
#endif

#include <vector>
using namespace std;

class VariableStatement : public Statement
{
private:
	vector<Expression*> *exprs;
public:
	VariableStatement(vector<Expression*> *exprs): exprs(exprs) {
		this->exprs = exprs;
	};
	void DumpValue(int indent)
	{
		this->Indent(indent);
		cout<<"VariableStatement"<<endl;
		for (std::vector<Expression*>::iterator iter = exprs->begin(); iter != exprs->end(); ++iter)
			(*iter)->DumpValue(indent + 1);
	}
};


class VariableExpression : public Expression {
private:
	Expression *ident, *init;
public:
	VariableExpression(Expression* ident, Expression* init) {
		this->ident = ident;
		this->init = init;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "VariableDeclaration" << endl;
		ident->DumpValue(indent + 1);
		init->DumpValue(indent + 1);
	};
};