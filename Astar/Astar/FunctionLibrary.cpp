#pragma once
#include "stdafx.h"
#include "FunctionLibrary.h"

BOOL DrawSquare(HDC hdc, POINT center, int width)
{
	return Rectangle(hdc, center.x - width, center.y - width, center.x + width, center.y + width);
}

