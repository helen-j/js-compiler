#include "jsValue.h"

jsString::jsString(string value) {
	this->value = value;
}
jsNumber* jsString::ToNumber() {
	//Todo - refer to specs 9.3.1
	return NULL;
}
jsString* jsString::ToString() {
	return this;
}
jsType jsString::Type() {
	return String;
}
jsBoolean* jsString::ToBool() {
	return NULL;
}


jsBoolean::jsBoolean(bool value) {
	this->value = value;
}

jsNumber* jsBoolean::ToNumber() {
	if (value) return new jsNumber(1);
	else return new jsNumber(0);
	//return NULL;
}

jsString* jsBoolean::ToString() {
	if (value) return new jsString("TRUE");
	else return new jsString("FALSE");
	//return NULL;
}

jsType jsBoolean::Type() {
	return Bool;
}
jsBoolean* jsBoolean::ToBool() {
	return this;
}

jsNumber::jsNumber(double value) {
	this->value = value;
}
jsType jsNumber::Type() {
	return Number;
}
jsNumber* jsNumber::ToNumber() {
	return this;
}
jsString* jsNumber::ToString() {
	string s = std::to_string(value);
	//remove trailing zeros
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	// remove trailing point
	if (s.back() == '.')
		s.pop_back();
	return new jsString(s);
}

jsBoolean* jsNumber::ToBool() {
		if (this->value == 0) {
			return new jsBoolean(false);
		}
		else {
			return new jsBoolean(true);
		}
}


jsObject::jsObject() {
		this->property_table.clear();
	}

jsType jsObject::Type() {
	return Object;
}
jsString* jsObject::ToString() {
	//NOT DONE
	return NULL;
}
jsBoolean* jsObject::ToBool() {
	return new jsBoolean(true);
}
jsNumber* jsObject::ToNumber() {
	//NOT DONE
	return NULL;
}
