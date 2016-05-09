#pragma once
#include <string>
using namespace std;
enum jsType {Number,String};
class jsNumber;
class jsString;


class jsValue 
{
public:
	virtual jsType Type() = 0;
	virtual jsNumber* ToNumber() = 0;
	virtual jsString* ToString() = 0;
};



class jsString : public jsValue {
public:
	string value;
public:
	jsString(string value) {
		this->value = value;
	};
	jsNumber* ToNumber() {
		//Todo - refe to specs 9.3.1
		return NULL;
	}
	jsString* ToString() {
		return this;
	}
	jsType Type() {
		return String;
	};
};
class jsNumber : public jsValue {
public:
	double value;
public:
	jsNumber(double value){
		this->value = value;
	};
	jsType Type() {
		return Number;
	};
	jsNumber* ToNumber() {
		return this;
	}
	jsString* ToString() {
		//Todo - remove decimals
		return new jsString(std::to_string(value));
	}
};



jsValue* Plus(jsValue* lprim, jsValue* rprim) {
	if (lprim->Type() == String || rprim->Type() == String) {
		return new jsString(lprim->ToString()->value + rprim->ToString()->value);
	}
	else
		return new jsNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
}