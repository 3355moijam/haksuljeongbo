#include "stdafx.h"
#include "class\GeometricObject\Rectangle.h"
#include "class\GeometricObject\Triangle.h"
#include "class\GeometricObject\Circle.h"

int main()
{
	
	double a;
	cout << "반지름 입력:" << endl;
	cout << "radius: ";
	cin >> a;
	cin.ignore();

	Circle2D circle(a);
	cout << "색깔을 골라주세요.(문자로 입력)";
	string k;
	cin >> k;
	circle.setColor(k);

	cout << "고른 색으로 채울까요?(0: 아니오, 1:네)";
	bool isfill;
	cin >> isfill;
	circle.setFilled(isfill);
	

	cout << "둘레: " << circle.getPerimeter() << endl;
	cout << "면적: " << circle.getArea() << endl;
	cout << "색깔: " << circle.getColor() << endl;
	cout << "채우기여부: " << circle.getFilled() << endl;

	
}

