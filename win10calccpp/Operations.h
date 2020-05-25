#pragma once

#include "IOperation.h"

ref class AdditionOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return ChildOpLeft->Calc() + ChildOpRight->Calc(); }
};

ref class SubstractionOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return ChildOpLeft->Calc() - ChildOpRight->Calc(); }
};

ref class MultiplicationOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return ChildOpLeft->Calc() * ChildOpRight->Calc(); }
};

ref class DivisionOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return ChildOpLeft->Calc() / ChildOpRight->Calc(); }
};

ref class ModuloOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return fmod(ChildOpLeft->Calc(), ChildOpRight->Calc()); }
};


ref class PowOperation : public BinaryOperation
{
public:
	ldbl Calc() override { return pow(ChildOpLeft->Calc(), ChildOpRight->Calc()); }
};