#pragma once
#include "ICalculable.h"
ref class Constant : public ICalculable
{
public:
	double Val;
	Constant(double val) { Val = val; }
	virtual double Calc() override;

	static bool TryParse(String^ input, Constant^ result);
};