#pragma once
#include "omok_framework.h"
#include "FunctionLibrary.h"

POINT& operator-=(POINT& left, const POINT& right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

POINT& operator-=(POINT& left, int num)
{
	left.x -= num;
	left.y -= num;
	return left;
}

POINT& operator+=(POINT& left, int num)
{
	left.x += num;
	left.y += num;
	return left;
}