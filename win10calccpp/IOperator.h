#pragma once

#include "ICalculable.h"

// this file contains a declaration for the IOperator interface
// requires each derived operator class to have a precedence and a Calc() function
// this class also has a static member used to parse a string into an operator class

ref class IOperator
{
public:
	virtual int GetPrecedence() = 0;
	virtual double Calc(ICalculable^ left, ICalculable^ right) = 0;

	// a list of all available operator symbols
	static array<String^>^ OperatorSymbols{ L"+", L"-", L"*", L"/", L"mod", L"^", L"base_log", L"yroot" };

	// creates an operator object from a string token
	// defined in IOperator.cpp
	static IOperator^ ParseToken(String^ token);
};