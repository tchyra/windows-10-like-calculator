#pragma once

#include "ICalculable.h"
#include "IOperator.h"

using namespace System::Collections::Generic;

ref class Expression : public ICalculable
{
public:
	List<ICalculable^>^ Calculables = gcnew List<ICalculable^>();
	List<IOperator^>^ Operators = gcnew List<IOperator^>();

	virtual double Calc() override;

	static List<String^>^ ParseTokens(String^ input);
	static bool TryParse(String^ input, Expression^% result);
};

