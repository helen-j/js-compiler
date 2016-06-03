#pragma once
#include <string>
#include <map>
#include "jsValue.h"
using namespace std;


class jsObject{
private:
	map<string, jsValue*> property_table;
public:
	jsObject() {
		this->property_table.clear();
	}
	void set(string propertyName, jsValue* propertyValue) {
		property_table[propertyName]= propertyValue;
	}
	jsValue* get(string propertyName) {
		map<string, jsValue*>::iterator it = property_table.find(propertyName);
		if (it != property_table.end())
			return it->second;
		return NULL;
	}
};

