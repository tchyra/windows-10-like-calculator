#pragma once

#include "ICalculable.h"

ref class Function : public ICalculable
{
public:
	ICalculable^ Argument;
	Function(ICalculable^ arg);

	static bool TryParse(String^ token, Function^% result);
};

