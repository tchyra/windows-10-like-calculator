#include "Function.h"
#include "Functions.h"

// this function is used to try and create a function object from a string token, and is very ugly about it.
// each condition here checks if the token starts with a [name](, and if it does, parses it's contents ([name]([contents])) into a calculable that then gets used in the function's constructor.
bool Function::TryParse(String^ token, Function^% result)
{
	result = nullptr;
	if (token->StartsWith(L"sqrt("))
		result = gcnew SqrtFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	else if (token->StartsWith(L"sqr("))
		result = gcnew SqrFunction(ICalculable::ParseToken(token->Substring(4, token->Length - 5)));

	else if (token->StartsWith(L"abs("))
		result = gcnew AbsFunction(ICalculable::ParseToken(token->Substring(4, token->Length - 5)));

	else if (token->StartsWith(L"fact("))
		result = gcnew FactorialFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	else if (token->StartsWith(L"ln("))
		result = gcnew LnFunction(ICalculable::ParseToken(token->Substring(3, token->Length - 4)));

	else if (token->StartsWith(L"log("))
		result = gcnew LogFunction(ICalculable::ParseToken(token->Substring(4, token->Length - 5)));

	else if (token->StartsWith(L"cuberoot("))
		result = gcnew CubeRootFunction(ICalculable::ParseToken(token->Substring(9, token->Length - 10)));

	else if (token->StartsWith(L"cube("))
		result = gcnew CubeFunction(ICalculable::ParseToken(token->Substring(5, token->Length - 6)));

	else if (token->StartsWith(L"-("))
		result = gcnew NegateFunction(ICalculable::ParseToken(token->Substring(2, token->Length - 3)));

	else if (token->StartsWith(L"10^("))
		result = gcnew TenToXFunction(ICalculable::ParseToken(token->Substring(4, token->Length - 5)));

	else if (token->StartsWith(L"2^("))
		result = gcnew TwoToXFunction(ICalculable::ParseToken(token->Substring(3, token->Length - 4)));

	else if (token->StartsWith(L"e^("))
		result = gcnew EToXFunction(ICalculable::ParseToken(token->Substring(3, token->Length - 4)));

	else if (token->StartsWith(L"1/("))
		result = gcnew ReciprocalFunction(ICalculable::ParseToken(token->Substring(3, token->Length - 4)));

	// return true if a function object has been created, false otherwise.
	return result != nullptr;
}