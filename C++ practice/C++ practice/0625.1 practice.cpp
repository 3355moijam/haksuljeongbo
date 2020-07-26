#include "stdafx.h"
#include "class\Rectangle\Rectangle.h"


int main()
{
	Rectangle a(4, 40);
	Rectangle b(3.5, 35.9);

	cout << "a : " << endl;
	cout << "W: " << a.getWidth() << " H: " << a.getHeight() 
		<< " Area: " << a.getArea() << " Perimeter: " << a.getPerimeter() << endl << endl;

	cout << "b : " << endl;
	cout << "W: " << b.getWidth() << " H: " << b.getHeight() 
		<< " Area: " << b.getArea() << " Perimeter: " << b.getPerimeter() << endl;

	return 0;
}
