#pragma once

#include <cstdarg>
#include <iostream>
using namespace std;

class Node
{
public:
	virtual void DumpValue(int indent) = 0;
	void Indent(int N)
	{
		for (int i = 0; i < N; i++)
			printf("    ");
	}
	void label(int i, char* fmt, ...)
	{
		Indent(i);
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}
};
