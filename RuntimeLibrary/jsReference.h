#pragma once
#include <string>
#include <iostream>
#include <map>
#include "jsValue.h"
#include "jsObject.h"

using namespace std;

class jsReference: public jsValue 
{
public:
	jsObject* base;
	   string name;

public:
	jsReference(jsObject* base, string name) 
	{
		this->base = base;
		this->name = name;
	}
};

