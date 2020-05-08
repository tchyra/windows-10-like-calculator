#pragma once

#include "ICalculable.h"

ref class IOperator
{
public:
	virtual int GetPrecedence() = 0;
	virtual double Calc(ICalculable^ left, ICalculable^ right) = 0;
	static IOperator^ ParseToken(String^ token);

	static array<String^>^ OperatorSymbols{ L"+", L"-", L"*", L"/", L"mod", L"^", L"base_log", L"yroot" };
};