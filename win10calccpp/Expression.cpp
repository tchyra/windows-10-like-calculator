#include "Expression.h"
#include "Exceptions.h"
#include "IOperator.h"
#include "Constant.h"

// calculates this expression
double Expression::Calc()
{
	// find operator of highest priority by going left to right
	// remove the operator from the operator list
	// remove the left and right calculables from the list
	// insert a new constant calculable where the left and right calculables were
	// repeat until the operator list is empty

	while (Operators->Count > 0)
	{
		int minPr = Operators[0]->GetPrecedence();
		int opIndex = 0;

		for (int i = 1; i < Operators->Count; i++)
		{
			if (Operators[i]->GetPrecedence() < minPr)
			{
				minPr = Operators[i]->GetPrecedence();
				opIndex = i;
			}
		}

		double result = Operators[opIndex]->Calc(Calculables[opIndex], Calculables[opIndex + 1]);

		Calculables->RemoveAt(opIndex + 1);
		Calculables->RemoveAt(opIndex);
		Calculables->Insert(opIndex, gcnew Constant(result));
		Operators->RemoveAt(opIndex);
	}

	return Calculables[0]->Calc();
}

// splits an expression string into a list of tokens (these can be constants, functions, expressions or operators)
// used in Expression::TryParse
// sample expression:	(2 + 5) * sqrt(5 / 2) + 8
// parsed tokens:		"2 + 5", "*", "sqrt(5 / 2)", "+", "8"
List<String^>^ Expression::ParseTokens(String^ input)
{
	List<String^>^ result = gcnew List<String^>();

	String^ token = L"";
	bool tokenIsFunction = false;
	bool finishToken = false;

	int leftParCnt = 0;

	for (int pos = 0; pos < input->Length; pos++)
	{
		// if the current position is a space, the current token ended, unless we're taking in a whole parenthesis
		if (input[pos] == L' ' && leftParCnt == 0)
		{
			// mark token end
			finishToken = true;
		}

		// the current position is an opening parenthesis
		else if (input[pos] == L'(')
		{
			if (token != L"") tokenIsFunction = true;

			// add this parenthesis to the token if it's not the first parenthesis or the token is a function token
			if (leftParCnt > 0 || tokenIsFunction)
				token += L"(";

			// mark entering a parenthesis
			leftParCnt++;
		}

		// the current position is a closing parenthesis
		else if (input[pos] == L')')
		{
			// mark exiting a parenthesis
			leftParCnt--;

			// add this parenthesis to the token if it's not the last parenthesis or the token is a function token
			if (leftParCnt > 0 || tokenIsFunction)
				token += L")";

			// if this was the last parenthesis at the end of the whole expression, finish the token
			if (leftParCnt == 0 && pos == input->Length - 1)
				// mark token end
				finishToken = true;
		}

		// any other character
		else
		{
			// append to token
			token += input[pos];
		}

		// finish the token if it was marked as finished or this was the last character
		if (finishToken || pos == input->Length - 1)
		{
			result->Add(token);
			token = L"";
			finishToken = false;
		}
	}

	return result;
}

// tries to create an expression object from an expression string
bool Expression::TryParse(String^ input, Expression^% result)
{
	result = gcnew Expression();

	// split input string into tokens
	List<String^>^ tokens;
	tokens = ParseTokens(input);

	try
	{
		// parse calculable tokens
		for (int i = 0; i < tokens->Count; i += 2)
		{
			result->Calculables->Add(ICalculable::ParseToken(tokens[i]));
		}

		// parse operator tokens
		for (int i = 1; i < tokens->Count; i += 2)
		{
			result->Operators->Add(IOperator::ParseToken(tokens[i]));
		}

		// mark parsing as failed if the number of calculables isn't greater by 1 than the number of operators
		if (result->Calculables->Count != result->Operators->Count + 1)
			return false;

		// mark parsing as successful
		return true;
	}
	catch (const ParseException^ ex)
	{
		// mark parsing as failed if a ParseException was thrown
		return false;
	}
}
