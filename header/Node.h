#pragma once
#include <string>
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

/*class Statement : public Node { };

class Expression : public Node { };

class AssignmentExpression : public Expression {
private:
	string Myname;
	Expression *lhs, *rhs;
public:
	AssignmentExpression(Expression* lhs, Expression* rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->Myname = "AssignmentExpression";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		lhs->DumpValue(indent + 2);
		rhs->DumpValue(indent + 2);
	};
};

class IdentifierExpression : public Expression
{
private:
	string name;
	string Myname;
public:
	IdentifierExpression(string name)
	{
		this->name = name;
		this->Myname = "IdentifierName";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		this->Indent(indent + 2);
		cout << "{" << endl;
		this->Indent(indent + 3);
		cout << name << endl;
		this->Indent(indent + 2);
		cout << "}" << endl;
	};
};

class IntegerLiteralExpression : public Expression
{
private:
	int value;
	string Myname;
public:
	IntegerLiteralExpression(int value)
	{
		this->value = value;
		this->Myname = "IntegerLiteral";
	};
	void DumpValue(int indent) {
		this->Indent(indent);
		cout << Myname << endl;
		this->Indent(indent + 2);
		cout << "{" << endl;
		this->Indent(indent + 3);
		cout << value << endl;
		this->Indent(indent + 2);
		cout << "}" << endl;
	};
};
*/