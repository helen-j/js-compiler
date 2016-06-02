#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;
enum jsType {Number,String,Bool,Reference,Undefined,Null,Object};

class jsString;
class jsNumber;
class jsBoolean;

class jsValue 
{
public:
	virtual jsType Type() = 0;
	virtual jsNumber* ToNumber() = 0;
	virtual jsString* ToString() = 0;
	virtual jsBoolean* ToBool() = 0;
};

class jsString : public jsValue {
public:
	string value;
public:
	__declspec(dllexport) jsString(string);
	__declspec(dllexport) jsNumber* ToNumber();
	__declspec(dllexport) jsString* ToString();
	__declspec(dllexport) jsType Type();
	__declspec(dllexport) jsBoolean* ToBool();
};


class jsBoolean : public jsValue {
public:
	bool value;
public:
	__declspec(dllexport) jsBoolean(bool);
	__declspec(dllexport) jsNumber* ToNumber();
	__declspec(dllexport) jsString* ToString();
	__declspec(dllexport) jsType Type();
	__declspec(dllexport) jsBoolean* ToBool();
};

class jsNumber : public jsValue {
public:
	double value;
public:
	__declspec(dllexport) jsNumber(double);
	__declspec(dllexport) jsType Type();
	__declspec(dllexport) jsNumber* ToNumber();
	__declspec(dllexport) jsString* ToString();
	__declspec(dllexport) jsBoolean* ToBool();
};

class jsObject : public jsValue {
public:
	map<string, jsValue*> property_table;
public:
	__declspec(dllexport) jsObject();
	__declspec(dllexport) jsType Type();
	__declspec(dllexport) jsNumber* ToNumber();
	__declspec(dllexport) jsString* ToString();
	__declspec(dllexport) jsBoolean* ToBool();
public:
	void set(string propertyName, jsValue* propertyValue) {
		property_table[propertyName] = propertyValue;
	}
	jsValue* get(string propertyName) {
		map<string, jsValue*>::iterator it = property_table.find(propertyName);
		if (it != property_table.end())
			return it->second;
		return NULL;
	}
};