#include "ICalculable.h"
#include "Expression.h"
#include "Constant.h"
#include "Function.h"
#include "Exceptions.h"

ICalculable^ ICalculable::ParseToken(String^ token)
{
	// check if token is a constant
	double val;
	if (Double::TryParse(token, val))
		return (ICalculable^)gcnew Constant(val);

	// check if token is a function
	Function^ func;
	if (Function::TryParse(token, func))
		return func;

	// finally try parsing token as expression
	Expression^ expr;
	if (Expression::TryParse(token, expr))
		return expr;

	// throw exception if we got this far, the token can't be parsed
	throw gcnew ParseException(L"Could not parse token: { " + token + L" }");
}