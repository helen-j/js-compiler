#pragma once
#include <string>
#include <iostream>
#include <map>
#include "jsValue.h"

using namespace std;

class jsReference : public jsValue
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
	jsType Type() {
		return Reference;
	}
	jsNumber* ToNumber() {
		return NULL;
	}
	jsString* ToString() {
		return NULL;
	}
	jsBoolean* ToBool() {
		return NULL;
	}
private:
	jsObject* GetBase() { return this->base; }
	string GetReferenceName() { return this->name; }
};