#include <math.h>

#include "Operators.h"
#include "Exceptions.h"

using namespace std;

double AdditionOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return left->Calc() + right->Calc();
}

double SubstractionOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return left->Calc() - right->Calc();
}

double MultiplicationOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return left->Calc() * right->Calc();
}

// x / y
// throws CalcException when right = 0
double DivisionOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	double rightArg = right->Calc();

	if (rightArg == 0) throw gcnew CalcException("Cannot divide by 0.");

	return left->Calc() / rightArg;
}

double ExpotentiationOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return pow(left->Calc(), right->Calc());
}


double ModuloOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return fmod(left->Calc(), right->Calc());
}

// log x y
// throws CalcException when left or right <= 0 and when left = 1.
double BaseLogOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	double baseArg = left->Calc();
	double aArg = right->Calc();

	if (baseArg <= 0 || aArg <= 0) throw gcnew CalcException("Arguments used with operator base_log cannot be less than or equal to 0.");
	else if (baseArg == 1) throw gcnew CalcException("Logarithm base used with operator base_log cannot be equal to 1.");

	return Math::Log(aArg, baseArg); // left and right swapped on purpose here!
}

// x^1/y
// throws CalcException when y is even and x is less than 0.
double YRootOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	double leftArg = left->Calc();
	double rightArg = right->Calc();

	if (fmod(rightArg, 2) == 0 && leftArg < 0) throw gcnew CalcException("When the fractional exponent is even, the base cannot be less than 0.");

	return Math::Pow(leftArg, 1.0/rightArg);
}