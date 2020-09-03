#pragma once
#include "stdafx.h"
#include "FunctionLibrary.h"


bool operator<(const Point& left, const Point& right)
{
	if (left.y == right.y)
		return left.x < right.x;
	else
		return left.y < right.y;
}

bool operator==(const Point& left, const Point& right)
{
	return (left.x == right.x) && (left.y == right.y);
}