#include <math.h>

#include "Functions.h"
#include "Exceptions.h"

using namespace System;

// this file contains definitions for Calc() methods of all functions

inline double sqr(double x) { return x * x; }
inline double cube(double x) { return x * x * x; }

// throws CalcException on negative arguments
double SqrtFunction::Calc()
{
	double arg = Argument->Calc();
	if (arg < 0) throw gcnew CalcException(L"Argument passed to sqrt() can't be negative.", L"Invalid input");
	return Math::Sqrt(arg);
}

double CubeRootFunction::Calc() { return Math::Pow(Argument->Calc(), 1.0 / 3); }


double SqrFunction::Calc() { return sqr(Argument->Calc()); }
double CubeFunction::Calc() { return cube(Argument->Calc()); }

double AbsFunction::Calc() { return Math::Abs(Argument->Calc()); }

double FactorialFunction::Calc() { return tgamma(Argument->Calc() + 1); }

// throws CalcException on arguments <= 0
double LnFunction::Calc()
{
	double arg = Argument->Calc();
	if (arg <= 0) throw gcnew CalcException(L"Argument passed to ln() can't be negative.", L"Invalid input");
	return Math::Log(Argument->Calc());
}

// throws CalcException on arguments <= 0
double LogFunction::Calc()
{
	double arg = Argument->Calc();
	if (arg <= 0) throw gcnew CalcException(L"Argument passed to log() can't be negative.", L"Invalid input");
	return Math::Log10(Argument->Calc());
}

double NegateFunction::Calc() { return -Argument->Calc(); }

double TenToXFunction::Calc() { return Math::Pow(10, Argument->Calc()); }
double TwoToXFunction::Calc() { return Math::Pow(2, Argument->Calc()); }
double EToXFunction::Calc() { return Math::Pow(Math::E, Argument->Calc()); }

// throws CalcException on arguments = 0
double ReciprocalFunction::Calc()
{
	double arg = Argument->Calc();
	if (arg == 0) throw gcnew CalcException(L"Division by 0 - Argument passed to 1/() can't be equal to 0.", L"Cannot divide by 0");
	return 1.0 / Argument->Calc();
}