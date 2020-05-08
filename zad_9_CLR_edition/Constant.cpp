#include "Constant.h"

double Constant::Calc() { return Val; }

bool Constant::TryParse(String^ input, Constant^ result)
{
	double v;

	if (Double::TryParse(input, v))
	{
		result = gcnew Constant(v);
		return true;
	}

	return false;
}