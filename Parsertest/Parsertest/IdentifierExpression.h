#pragma once
#include "Expression.h"
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

