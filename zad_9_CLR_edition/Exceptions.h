#pragma once

using namespace System;

ref class ParseException : public Exception
{
public:
	ParseException(String^ message) : Exception(message) {}
};

ref class CalcException : public Exception
{
public:
	CalcException(String^ message) : Exception(message) {}
};