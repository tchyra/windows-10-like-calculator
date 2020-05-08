#include <math.h>

#include "Operators.h"

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

double DivisionOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return left->Calc() / right->Calc();
}

double ExpotentiationOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return pow(left->Calc(), right->Calc());
}


double ModuloOperator::Calc(ICalculable^ left, ICalculable^ right)
{
	return fmod(left->Calc(), right->Calc());
}