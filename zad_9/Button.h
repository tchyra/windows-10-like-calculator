#pragma once

// standard libs
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class Button
{
public:
	int X, Y, Width, Height;
	TCHAR Text[];

	Button(int, int, int, int, const char[]);
};

