#include "MyPoint.h"
#include <cmath>

MyPoint::MyPoint() : x(0), y(0)
{ 
}
MyPoint::MyPoint(double inx, double iny) : x(inx), y(iny)
{
}
MyPoint::~MyPoint() 
{
}
double MyPoint::getDistance(MyPoint & dot)
{
	return sqrt(pow(x - dot.getX(), 2) + pow(y - dot.getY(), 2));
}