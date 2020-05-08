#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class IDrawable
{
public:
	virtual void Draw(HDC) = 0;
};

