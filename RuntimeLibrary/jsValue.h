#pragma once
#include <string>
#include <iostream>

using namespace std;
enum jsType {Number,String,Bool};

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

