#include <String> 
#include "Node.h"
#include "Expression.h"
#include "AssignmentExpression.h"
#include "IdentifierExpression.h"
#include "IntegerLiteralExpression.h"
using namespace std;

int main(int argc, char* argv[])
{
	string x;
	x = 'x';
	Expression *root = new AssignmentExpression(new IdentifierExpression(x), new IntegerLiteralExpression(42));
	root->DumpValue(1);
}