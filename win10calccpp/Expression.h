#pragma once

#include "ICalculable.h"
#include "IOperator.h"

using namespace System::Collections::Generic;


// Expression is a set of operators and calculables (constants, functions or other expressions) in a format of calculable operator calculable etc.
// sample expression: (2 + 5) * sqrt(5 / 2) + 8

ref class Expression : public ICalculable
{
public:
	List<ICalculable^>^ Calculables = gcnew List<ICalculable^>();
	List<IOperator^>^ Operators = gcnew List<IOperator^>();

	virtual double Calc() override;

	static List<String^>^ ParseTokens(String^ input);
	static bool TryParse(String^ input, Expression^% result);
};

