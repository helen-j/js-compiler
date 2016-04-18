#pragma once
#ifndef Node_H_
#include "Node.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class Statement : public Node { };

class ExpressionStatement : public Statement
{
private :
	Expression *expr;
public:
	ExpressionStatement(Expression *expr) : expr(expr) {
		this->expr = expr;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "ExpressionStatement" << endl;
	    expr->DumpValue(indent + 1);
	};
};