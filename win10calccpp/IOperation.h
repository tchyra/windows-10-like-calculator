#include "defs.h"

#pragma once
ref class IOperation
{
public: 
	virtual ldbl Calc() = 0;
};

ref class BinaryOperation : public IOperation
{
public:
	IOperation^ ChildOpLeft;
	IOperation^ ChildOpRight;
};

