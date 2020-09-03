#pragma once

struct Point
{
	short x;
	short y;

	Point() : x(0), y(0) {}
	template<typename T>
	Point(T _x, T _y) : x(static_cast<short>(_x)), y(static_cast<short>(_y)) {}

};

bool operator<(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);