#pragma once
#include "Node.h"
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
};


class IdentifierExpression : public Expression
{
	private :
		char *name;
	public:
		IdentifierExpression(char *name)
		{
			this->name = name;
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
};