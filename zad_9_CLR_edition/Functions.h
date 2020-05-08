#pragma once

#include "Function.h"

ref class SqrtFunction : public Function
{
public:
	SqrtFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

ref class SqrdFunction : public Function
{
public:
	SqrdFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

ref class AbsFunction : public Function
{
public:
	AbsFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

ref class FactorialFunction : public Function
{
public:
	FactorialFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};
