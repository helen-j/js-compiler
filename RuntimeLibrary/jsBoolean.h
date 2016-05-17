#pragma once
#include "jsValue.h"

using namespace std;

class jsBoolean : public jsValue {
public:
	bool value;
public:
	jsBoolean(bool value) {
		if (value) { this->value = true; }
		else { this->value =false; }
	};

	jsNumber* ToNumber() {
		//Todo - refer to specs 9.3.1
		return NULL;
	};

	jsString* ToString() {
		return NULL;
	}
	jsType Type() {
		return Bool;
	}
	jsBoolean* ToBool() {
		return this;
	}
};

