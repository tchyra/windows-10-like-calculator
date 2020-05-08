#include <math.h>

#include "Functions.h"
#include "Exceptions.h"

using namespace System;

double sqrd(double x) { return x * x; }

double SqrtFunction::Calc() { return Math::Sqrt(Argument->Calc()); }
double SqrdFunction::Calc() { return sqrd(Argument->Calc()); }
double AbsFunction::Calc() { return Math::Abs(Argument->Calc()); }

double FactorialFunction::Calc() { 
	double arg = Argument->Calc();
	if ((int)arg == arg && arg < 0) throw gcnew CalcException(L"Invalid input for fact() function. The argument cannot be a negative integer.");
	return tgamma(arg + 1); 
}