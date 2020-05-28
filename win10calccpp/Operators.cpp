#include <math.h>

#include "Operators.h"
#include "Exceptions.h"

using namespace std;

// this file defines methods used to calculate values for all available operators.
// every operator class should be declared in Operators.h and then it's calc method should be defined here.

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

	if (rightArg == 0) throw gcnew CalcException(L"Cannot divide by 0.", L"Cannot divide by 0");

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

	if (baseArg <= 0 || aArg <= 0) throw gcnew CalcException(L"Arguments used with operator base_log cannot be less than or equal to 0.", L"Invalid input");
	else if (baseArg == 1) throw gcnew CalcException(L"Logarithm base used with operator base_log cannot be equal to 1.", L"Invalid input");

	return Math::Log(aArg, baseArg); // left and right swapped on purpose here!
}

// x^1/y
// throws CalcException when y is even and x is less than 0.
double YRootOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	double leftArg = left->Calc();
	double rightArg = right->Calc();

	if (fmod(rightArg, 2) == 0 && leftArg < 0) throw gcnew CalcException(L"When the fractional exponent is even, the base cannot be less than 0.", L"Invalid input");

	return Math::Pow(leftArg, 1.0/rightArg);
}