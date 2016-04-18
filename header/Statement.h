#pragma once
#include "Node.h"
#include "Expression.h"
using namespace std;

class Statement : public Node { };
class ExpressionStatement : public Statement
{
private :
	Expression *expr;
public:
	ExpressionStatement(Expression *expr) : expr(expr) {};

};