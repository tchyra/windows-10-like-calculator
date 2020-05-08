#include "Button.h"

// standard libs
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

Button::Button(int x, int y, int width, int height, const TCHAR text[])
{
	X = x;
	Y = y;
	Width = width;
	Height = height;
	_tcscpy(Text, text);
}
