#pragma once
#include "Expression.h"
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

