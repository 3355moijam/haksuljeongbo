#include "stdafx.h"
#include "class\GeometricObject\Rectangle.h"
#include "class\GeometricObject\Triangle.h"
#include "class\GeometricObject\Circle.h"

int main()
{
	
	double a;
	cout << "������ �Է�:" << endl;
	cout << "radius: ";
	cin >> a;
	cin.ignore();

	Circle2D circle(a);
	cout << "������ ����ּ���.(���ڷ� �Է�)";
	string k;
	cin >> k;
	circle.setColor(k);

	cout << "�� ������ ä����?(0: �ƴϿ�, 1:��)";
	bool isfill;
	cin >> isfill;
	circle.setFilled(isfill);
	

	cout << "�ѷ�: " << circle.getPerimeter() << endl;
	cout << "����: " << circle.getArea() << endl;
	cout << "����: " << circle.getColor() << endl;
	cout << "ä��⿩��: " << circle.getFilled() << endl;

	
}

