#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class ICalculable
{
public:
	virtual double Calc() = 0;

	static ICalculable^ ParseToken(String^ token);
};
