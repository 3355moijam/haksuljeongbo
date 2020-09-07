#include "stdafx.h"
#include "Point.h"

bool Point::isOnMap(short _width, short _height) const
{
	return (x_ >= 0 || x_ < _width || y_ >= 0 || y_ < _height);
}

bool Point::operator<(const Point& right) const
{
	if (y_ == right.y_)
		return x_ < right.x_;
	else
		return y_ < right.y_;
}

bool Point::operator==(const Point& right) const
{
	return (x_ == right.x_) && (y_ == right.y_);
}
