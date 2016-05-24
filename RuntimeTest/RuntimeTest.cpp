#include "jsValue.h"
#include "jsObject.h"
#include "jsFunction.h"

int main(int argc, char* argv[])
{	
	jsObject* global = new jsObject();

	global->set("x", new jsNumber(42));

	global->set("y", Plus(global->get("x"), new jsNumber(1)));

	consolelog(global->get("y"));

	/*global->set("x", new jsString("hello"));

	//y=x+4;
	global->set("y", Plus(global->get("x"), new jsNumber(4)));

	consolelog(global->get("y"));
	*/
	//z=(x==y)
	global->set("z", Lessthan(global->get("x"), (global->get("y"))));

	/*
	//y=x-5 test for subtraction
	global->set("y", Minus(global->get("x"), new jsNumber(5)));
	consolelog(global->get("y"));
	*/
	
	// if (z)
	if (global->get("z")->ToBool()->value){

		cout << "x=hello" <<endl;
	}

	//INCREMENT OPERATOR TEST
	/*global->set("x", new jsNumber(42));
	global->set("y", Increment(global->get("x")));
	consolelog(global->get("y"));*/



}