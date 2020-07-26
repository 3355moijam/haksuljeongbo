#include "stdafx.h"

struct dot
{
	float X;
	float Y;
};

float side(dot, dot);
float triExtent(dot, dot, dot);

int main()
{
	dot A, B, C;

	cout << "�ﰢ�� �� �������� ��ǥ�� �Է����ּ���." << endl;
	cout << "�� A�� x y" << endl;
	cin >> A.X >> A.Y;
	cin >> B.X >> B.Y;
	cin >> C.X >> C.Y;

	cout << "�ﰢ���� ���̴� " << triExtent(A, B, C) << "�Դϴ�." << endl;

	return 0;
}

float side(dot a, dot b)
{
	return pow(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2), 0.5);
}

float triExtent(dot a, dot b, dot c)
{
	float side1 = side(a, b);
	float side2 = side(b, c);
	float side3 = side(c, a);

	float s = (side1 + side2 + side3) / 2;

	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}