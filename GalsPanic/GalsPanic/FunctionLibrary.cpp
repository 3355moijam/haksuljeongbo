#pragma once
#include "framework.h"
#include "FunctionLibrary.h"

void DrawGrid(HDC hdc, int x1, int y1, int x2, int y2, int interval)
{
	for (int i = x1; i < x2; i += interval)
	{
		for (int j = y1; j < y2; j += interval)
		{
			MoveToEx(hdc, x1, j, NULL);
			LineTo(hdc, x2, j);
			MoveToEx(hdc, i, y1, NULL);
			LineTo(hdc, i, y2);
		}
	}
	MoveToEx(hdc, x2, y1, NULL);
	LineTo(hdc, x2, y2);
	MoveToEx(hdc, x1, y2, NULL);
	LineTo(hdc, x2, y2);
}

void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
}

void DrawCircle(HDC hdc, POINT center, int radius)
{
	Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

BOOL MoveToEx(HDC hdc, POINT to)
{
	return MoveToEx(hdc, to.x, to.y, NULL);
}

BOOL LineTo(HDC hdc, POINT to)
{
	return LineTo(hdc, to.x, to.y);
}