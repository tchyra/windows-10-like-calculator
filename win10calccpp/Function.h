#pragma once

#include "ICalculable.h"

// this file contains a declaration for the Function abstract class
// requires each derived function class to have a Calc() function
// this class also has a static member used to try to parse a string into a function class

// a Function is a function with a single calculable (constants, functions or other expressions) argument in a format of name(calculable).
// sample function: sqrt(5 / 2)

ref class Function : public ICalculable
{
public:
	ICalculable^ Argument;

	// base constructor for all functions that accepts a calculable argument
	Function(ICalculable^ arg) { Argument = arg; }

	static bool TryParse(String^ token, Function^% result);
};

