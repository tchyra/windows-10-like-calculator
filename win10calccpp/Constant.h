#pragma once
#include "ICalculable.h"
ref class Constant : public ICalculable
{
public:
	double Val;
	Constant(double val) { Val = val; }
	virtual double Calc() override { return Val; }

	static bool TryParse(String^ input, Constant^ result)
	{
		double v;

		if (Double::TryParse(input, v))
		{
			result = gcnew Constant(v);
			return true;
		}

		return false;
	}
};