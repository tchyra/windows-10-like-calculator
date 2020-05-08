#include "IOperator.h"
#include "Operators.h"
#include "Exceptions.h"

IOperator^ IOperator::ParseToken(String^ token)
{
	if (token == "+")
		return gcnew AdditionOperator();
	else if (token == L"-")
		return gcnew SubstractionOperator();
	else if (token == L"*")
		return gcnew MultiplicationOperator();
	else if (token == L"/")
		return gcnew DivisionOperator();
	else if (token == L"mod")
		return gcnew ModuloOperator();
	else if (token == L"^")
		return gcnew ExpotentiationOperator();

	throw gcnew ParseException(L"Could not parse token: { " + token + L" }");
}