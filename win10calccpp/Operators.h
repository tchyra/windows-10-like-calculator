#pragma once
#include "IOperator.h"

ref class AdditionOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 2; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};

ref class SubstractionOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 2; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};


ref class MultiplicationOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 1; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};

ref class DivisionOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 1; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};

ref class ModuloOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 1; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};


ref class ExpotentiationOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return 0; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};

ref class BaseLogOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return -1; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};

ref class YRootOperator : public IOperator
{
public:
	virtual int GetPrecedence() override { return -1; }
	virtual double Calc(ICalculable^ left, ICalculable^ right) override;
};