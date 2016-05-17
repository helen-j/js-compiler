#pragma once
#include <string>
#include <iostream>
using namespace std;
enum jsType {Number,String,Bool};
class jsNumber;
class jsString;
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
	jsString(string value) {
		this->value = value;
	};
	jsNumber* ToNumber() {
		//Todo - refer to specs 9.3.1
		return NULL;
	}
	jsString* ToString() {
		return this;
	}
	jsType Type() {
		return String;
	};
	jsBoolean* ToBool() {
		return NULL;
	}
};


class jsNumber : public jsValue {
public:
	double value;
public:
	jsNumber(double value){
		this->value = value;
	}
	jsType Type() {
		return Number;
	}
	jsNumber* ToNumber() {
		return this;
	}
	jsString* ToString() {
		string s = std::to_string(value);
		//remove trailing zeros
		s.erase(s.find_last_not_of('0') + 1, std::string::npos);
		// remove trailing point
		if (s.back() == '.') {
			s.pop_back();
			return new jsString(s);
		}
	}
	jsBoolean* ToBool() {
		/*if (this->Type() == Number) {
		if (value == 0)
			return new jsBoolean(false);
		else
			return new jsBoolean(true);
		}*/
		return NULL;
	};
};

class jsBoolean : public jsValue {
public:
	bool value;
public:
	jsBoolean(bool value) {
		this->value = value;
	};

	jsNumber* ToNumber() {
		//Todo - refer to specs 9.3.1
		return NULL;
	}
	jsString* ToString() {
		return NULL;
	}
	jsType Type() {
		return Bool;
	};
	jsBoolean* ToBool() {
		return this;
	}
};


jsValue* Plus(jsValue* lprim, jsValue* rprim) {
	if (lprim->Type() == String || rprim->Type() == String) {
		return new jsString(lprim->ToString()->value + rprim->ToString()->value);
	}
	else
		return new jsNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
}




jsValue* Equals(jsValue* lprim, jsValue* rprim) {
	//	1.	ReturnIfAbrupt(x).
	//		2.	ReturnIfAbrupt(y).
	//		3.	If Type(x) is the same as Type(y), then
	//		a.Return the result of performing Strict Equality Comparison    x == = y.

		if (lprim->Type() == rprim->Type()) {
			if (lprim->Type()==String )
				return new jsBoolean(lprim->ToString()->value == rprim->ToString()->value);
			else if (lprim->Type() == Number)
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);
			else if (lprim->Type() == Bool)
				return new jsBoolean(lprim->ToBool()->value == rprim->ToBool()->value);
		}
		else
//		4.	If x is null and y is undefined, return   true.
//		5.	If x is undefined and y is null, return    true.
/*			if (lprim == NULL)

			return new jsNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
		//*/

	//		6.	If Type(x) is Number and Type(y) is   String,
	//		return the result of the comparison  x == ToNumber(y).
			if ((lprim->Type() == Number) && (rprim->Type() == String))
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);

	//		7.	If Type(x) is String and Type(y) is   Number,
	//		return the result of the comparison ToNumber(x) == y.
			if ((lprim->Type() == String) && (rprim->Type() == Number))
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);

	//		8.	If Type(x) is Boolean, return the result of the comparison ToNumber(x) == y.
	//		9.	If Type(y) is Boolean, return the result of the comparison  x == ToNumber(y).
	//		10.	If Type(x) is either String, Number, or Symbol and Type(y) is Object, then return the result of the comparison  x == ToPrimitive(y).
	//		11.	If Type(x) is Object and Type(y) is either String, Number, or Symbol, then return the result of the comparison ToPrimitive(x) == y.
	//		12.	Return false.
	//return new jsBoolean(true);



}


	

void consolelog(jsValue* x) {
	cout << x->ToString()->value << endl;
}