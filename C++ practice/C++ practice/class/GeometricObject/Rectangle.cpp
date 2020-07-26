#include "Rectangle.h"

Rectangle2D::Rectangle2D()
{
	setWidth(1);
	setHeight(1);
}

Rectangle2D::Rectangle2D(double wth, double hght)
{
	setWidth(wth);
	setHeight(hght);
}

Rectangle2D::~Rectangle2D()
{

}

double Rectangle2D::getWidth()
{
	return width;
}
double Rectangle2D::getHeight()
{
	return height;
}
void Rectangle2D::setWidth(double wth)
{
	width = wth;
}
void Rectangle2D::setHeight(double hght)
{
	height = hght;
}
double Rectangle2D::getArea()
{
	return width * height;
}
double Rectangle2D::getPerimeter()
{
	return 2 * width + 2 * height;
}