#pragma once
#include "GeometricObject.h"

class Rectangle2D : public GeometricObject
{
private:
	double width;
	double height;
public:
	Rectangle2D();
	Rectangle2D(double, double);
	~Rectangle2D();
	double getWidth();
	double getHeight();
	void setWidth(double);
	void setHeight(double);
	double getArea();
	double getPerimeter();

};

