#include "Triangle.h"



Triangle2D::Triangle2D()
	:side1(1), side2(1), side3(1)
{
}

Triangle2D::Triangle2D(double a, double b, double c)
	: side1(a), side2(b), side3(c)
{
}

Triangle2D::~Triangle2D()
{
}

double Triangle2D::getArea()
{
	double s = (side1 + side2 + side3) / 2;
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
double Triangle2D::getPerimeter()
{
	return side1 + side2 + side3;
}