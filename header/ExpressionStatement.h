#pragma once
#ifndef Statement_H_
#include "Statement.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif
using namespace std;

class ExpressionStatement : public Statement
{
private:
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

class AssignmentExpression : public Expression {
private:
	Expression *lhs, *rhs;
public:
	AssignmentExpression(Expression* lhs, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << "AssignmentExpression" << endl;
		lhs->DumpValue(indent + 1);
		rhs->DumpValue(indent + 1);
	};
};