#pragma once
#ifndef Node_H_
#include "Node.h"
#endif

#ifndef Expression_H_

using namespace std;

class Expression : public Node {
public:
	virtual int GenCode(FILE* file) = 0;
};

#endif