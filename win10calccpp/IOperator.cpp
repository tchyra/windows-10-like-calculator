#include "IOperator.h"
#include "Operators.h"
#include "Exceptions.h"


// creates an operator object from a string token
// throws ParseException when the given token is not an operator
IOperator^ IOperator::ParseToken(String^ token)
{
	if (token == L"+")
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
	else if (token == L"base_log")
		return gcnew BaseLogOperator();
	else if (token == L"yroot")
		return gcnew YRootOperator();

	throw gcnew ParseException(L"Could not parse token: { " + token + L" }");
}