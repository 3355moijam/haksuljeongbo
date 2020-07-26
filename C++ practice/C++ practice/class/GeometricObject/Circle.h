#pragma once
#include "GeometricObject.h"
#define _USE_MATH_DEFINES // for C++
#include <math.h>

class Circle2D : public GeometricObject
{
private :
	double radius;
public:
	Circle2D();
	Circle2D(double);
	~Circle2D();
	double getArea() { return radius * radius * M_PI; }
	double getPerimeter() { return 2 * radius * M_PI; }
	double getRadius() { return radius; }
};

