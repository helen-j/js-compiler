#include "jsValue.h"

int main(int argc, char* argv[])
{

	jsValue* x = new jsNumber(42);

	jsValue* y = Plus(x, new jsNumber(4));

	consolelog(y);

	x = new jsString("hello");

	y = Plus(x, new jsNumber(4));

	consolelog(y);
}