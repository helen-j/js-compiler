#include "jsValue.h"
#include "jsObject.h"
#include "jsFunction.h"

int main(int argc, char* argv[])
{	
	jsObject* global = new jsObject();

	global->set("x", new jsNumber(42));

	global->set("y", Plus(global->get("x"), new jsNumber(0)));

	consolelog(global->get("y"));

	/*global->set("x", new jsString("hello"));

	//y=x+4;
	global->set("y", Plus(global->get("x"), new jsNumber(4)));

	consolelog(global->get("y"));
	*/
	//z=(x==y)
	global->set("z", Equals(global->get("x"), (global->get("y"))));

	
	// if (z)
	if (global->get("z")->ToBool()->value){

		cout << "x=hello" <<endl;
	}









}