#include "jsValue.h"
#include "jsObject.h"

int main(int argc, char* argv[])
{

	jsObject* global = new jsObject();

	global->set("x", new jsNumber(42));

	global->set("y", Plus(global->get("x"), new jsNumber(4)));

	consolelog(global->get("y"));

	global->set("x", new jsString("hello"));

	global->set("y", Plus(global->get("x"), new jsNumber(4)));

	consolelog(global->get("y"));

}