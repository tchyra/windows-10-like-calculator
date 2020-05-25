#pragma once

#include "Function.h"

// this file contains declaractions for all functions available within the calculator.

// x^1/2
ref class SqrtFunction : public Function
{
public:
	SqrtFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// x^1/3
ref class CubeRootFunction : public Function
{
public:
	CubeRootFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};


// x^2
ref class SqrFunction : public Function
{
public:
	SqrFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// x^3
ref class CubeFunction : public Function
{
public:
	CubeFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};


// |x|
ref class AbsFunction : public Function
{
public:
	AbsFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// x!
ref class FactorialFunction : public Function
{
public:
	FactorialFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// -x
ref class NegateFunction : public Function
{
public:
	NegateFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// 1/x
ref class ReciprocalFunction : public Function
{
public:
	ReciprocalFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};


// ln x
ref class LnFunction : public Function
{
public:
	LnFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// log x
ref class LogFunction : public Function
{
public:
	LogFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// 10^x
ref class TenToXFunction : public Function
{
public:
	TenToXFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// 2^x
ref class TwoToXFunction : public Function
{
public:
	TwoToXFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};

// e^x
ref class EToXFunction : public Function
{
public:
	EToXFunction(ICalculable^ arg) : Function(arg) {}
	virtual double Calc() override;
};