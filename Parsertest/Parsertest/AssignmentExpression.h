#pragma once
#include "Expression.h"
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

