#pragma once

#include <cstdarg>
#include <iostream>
using namespace std;

class Node
{
public:
	void emit(FILE* outputfile, char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		vfprintf(outputfile, fmt, args);
		fprintf(outputfile, "\n");
		va_end(args);
	}
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
