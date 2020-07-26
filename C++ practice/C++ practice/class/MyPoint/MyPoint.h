#pragma once
class MyPoint
{
private:
	double x;
	double y;
public:
	MyPoint();
	MyPoint(double x, double y);
	~MyPoint();
	double getX(void) { return x; }
	double getY(void) { return y; }
	void setX(double input) { x = input; }
	void setY(double input) { y = input; }
	double getDistance(MyPoint & dot);
};

