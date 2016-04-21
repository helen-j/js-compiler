#pragma once
#ifndef Node_H_
#include "Node.h"
#endif
#ifndef Expression_H_
#include "Expression.h"
#endif

#include <vector>

using namespace std;

class Statement : public Node { };


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
};