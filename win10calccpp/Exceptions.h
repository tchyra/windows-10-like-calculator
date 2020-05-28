#pragma once

using namespace System;

// this class contains custom exception classes for parsing and calculating

ref class ParseException : public Exception
{
public:
	ParseException(String^ message) : Exception(message) {}
};

ref class CalcException : public Exception
{
public:
	String^ DisplayMessage;
	CalcException(String^ message, String^ displayMessage) : Exception(message)
	{
		DisplayMessage = displayMessage;
	}
};