#pragma once
#include "GeometricObject.h"

class Triangle2D : public GeometricObject
{
private:
	double side1;
	double side2;
	double side3;
public:
	Triangle2D();
	Triangle2D(double, double, double);
	~Triangle2D();
	double getSide1() { return side1; }
	double getSide2() { return side2; }
	double getSide3() { return side3; }
	double getArea();
	double getPerimeter();
};

