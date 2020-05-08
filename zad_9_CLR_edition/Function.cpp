#include "Function.h"
#include "Functions.h"

Function::Function(ICalculable^ arg) { Argument = arg; }

bool Function::TryParse(String^ token, Function^% result)
{
	result = nullptr;
	if (token->StartsWith(L"sqrt("))
		result = gcnew SqrtFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	else if (token->StartsWith(L"sqrd("))
		result = gcnew SqrdFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	else if (token->StartsWith(L"abs("))
		result = gcnew AbsFunction(ICalculable::ParseToken(token->Substring(4, token->Length - 5)));

	else if (token->StartsWith(L"fact("))
		result = gcnew FactorialFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	return result != nullptr;
}