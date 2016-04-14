#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Expression : public Node
{
};

class AssignmentExpression : public Expression
{
	private:
		Expression *lhs, *rhs;
	public:
		AssignmentExpression(Expression* lhs, Expression* rhs)
		{
			this->lhs = lhs;
			this->rhs = rhs;
		}
		virtual Expression* getLHS() { return lhs; }
		virtual Expression* getRHS() { return rhs; }
		virtual void printAssignExpression() {
			cout << "Lefthandside expression is" << getLHS() << endl
				 << "Righthandside expression is" << getRHS() << endl;
		}
};


class IdentifierExpression : public Expression
{
	private:
		char *name;
	public:
		IdentifierExpression(char *name)
		{
			this->name = name;
		}
		virtual char getName() { return *name; }
		virtual void printIndentifierExpression() {
			cout << "Indentifier expression is" << getName() << endl;
		}
};

class IntegerLiteralExpression : public Expression
{
	private:
		int value;
	public:
		IntegerLiteralExpression(int value)
		{
			this->value = value;
		}
		virtual int getValue() {
			return value;
		}
		virtual void printIntLiteralExpression() {
			cout << "IntLiteral expression is" << getValue() << endl;
		}
};