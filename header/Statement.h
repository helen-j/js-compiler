#pragma once
#ifndef Node_H_
#include "Node.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif

#include <vector>

using namespace std;

class Statement : public Node {
public:
	virtual void GenCode(FILE* file) = 0;
};


class CompoundStatement : public Statement
{
private:
	vector<Statement*> *stmts;
public:
	CompoundStatement(vector<Statement*> *stmts) : stmts(stmts) { };
	void DumpValue(int indent)
	{
		this->Indent(indent);
		cout<<"CompoundStatement"<<endl;
		for (std::vector<Statement*>::iterator iter = stmts->begin(); iter != stmts->end(); ++iter)
			(*iter)->DumpValue(indent + 1);
	}
	void GenCode(FILE* file) {
		for (std::vector<Statement*>::iterator child = stmts->begin(); child != stmts->end(); ++child)
			(*child)->GenCode(file);
	};
};
