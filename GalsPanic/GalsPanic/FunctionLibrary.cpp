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

bool IsBetweenPt(POINT target, POINT p1, POINT p2, int mode)
{
	if (mode == 0)
	{
		if (p1.x == p2.x)
		{
			if (target.x != p1.x)
				return false;

			if (target.y >= p1.y && target.y <= p2.y)
				return true;
			else if (target.y <= p1.y && target.y >= p2.y)
				return true;
			else
				return false;
		}
		else if (p1.y == p2.y)
		{
			if (target.y != p1.y)
				return false;

			if (target.x >= p1.x && target.x <= p2.x)
				return true;
			else if (target.x <= p1.x && target.x >= p2.x)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (p1.x == p2.x)
		{
			if (target.x != p1.x)
				return false;

			if (target.x > p1.x && target.x < p2.x)
				return true;
			else if (target.x < p1.x && target.x > p2.x)
				return true;
			else
				return false;
		}
		else if (p1.y == p2.y)
		{
			if (target.y != p1.y)
				return false;

			if (target.y > p1.y && target.y < p2.y)
				return true;
			else if (target.y < p1.y && target.y > p2.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

bool operator==(const POINT& lhs, const POINT& rhs)
{
	if ((lhs.x == rhs.x) && (lhs.y == rhs.y))
		return true;

	return false;
}