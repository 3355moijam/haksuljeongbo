#pragma once

class Point
{
private:
	short x_;
	short y_;

public:
	short get_x() const
	{
		return x_;
	}

	void set_x(short x)
	{
		x_ = x;
	}

	__declspec(property(get = get_x, put = set_x)) short x;

	short get_y() const
	{
		return y_;
	}

	void set_y(short y)
	{
		y_ = y;
	}

	__declspec(property(get = get_y, put = set_y)) short y;

	Point() : x_(0), y_(0) {}
	template<typename T>
	Point(T _x, T _y) : x_(static_cast<short>(_x)), y_(static_cast<short>(_y)) {}

	bool isOnMap(short _width, short _height) const;

	bool operator<(const Point& right) const;
	bool operator==(const Point& right) const;
	Point operator*(int num) const;
	Point& operator*=(int num);
};
