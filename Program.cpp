#include "Expression.h"
#include "AssignmentExpression.h"
#include "IdentifierExpression.h"
#include "IntegerLiteralExpression.h"

int main(int argc, char* argv[])
{
	char x[2];
		Expression root = new AssignmentExpression(
							new IdentifierExpression(x),
								new IntegerLiteralExpression(42));
}