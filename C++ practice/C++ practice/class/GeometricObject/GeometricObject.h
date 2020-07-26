#pragma once
#include "../../stdafx.h"

class GeometricObject
{
private:
	bool filled;
	string color;
public:
	GeometricObject();
	virtual ~GeometricObject();
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	void setColor(string a) { color = a; }
	string getColor() { return color; }
	void setFilled(bool a) { filled = a; }
	bool getFilled() { return filled; }
};

