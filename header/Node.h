#pragma once
#ifndef _Node__H_
#define _Node_H_


#include <iostream>
using namespace std;

class Node { 
public:	
	void Indent(int n)
	{
		for (int i = 0; i < n; i++)
			cout << "    ";
	};
	virtual void DumpValue(int) {};
};

#endif