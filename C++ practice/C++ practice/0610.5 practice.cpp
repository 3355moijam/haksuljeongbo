#include "stdafx.h"
#include <cmath>
#include <Windows.h>

struct dot
{
	float X;
	float Y;
};

float distance(dot, dot);

int main()
{
	dot a = { 0 };
	dot b = { 0 };
	cout << "�� ���� ��ǥ�� �Է����ּ��� x, y" << endl;
	cout << "ù ��° ���� ��ǥ :" << endl;
	cin >> a.X >> a.Y;
	cout << "�� ��° ���� ��ǥ :" << endl;
	cin >> b.X >> b.Y;

	cout << "�� �� ������ �Ÿ� : " << distance(a, b) << endl;

	return 0;
}

float distance(dot a, dot b)
{
	float n = pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2);
	return pow(n, 0.5);
}