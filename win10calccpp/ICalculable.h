#pragma once

using namespace System;
using namespace System::Collections::Generic;


// this file contains a declaration for the ICalculable interface
// requires each derived class to have a Calc() function
// this class also has a static member used to parse a string into a calculable
// there are three types of calculables in use in this project, Constants, Functions and Expressions.

ref class ICalculable
{
public:
	virtual double Calc() = 0;

	static ICalculable^ ParseToken(String^ token);
};
