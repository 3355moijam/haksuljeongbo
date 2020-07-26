#include "stdafx.h"

struct dot
{
	float X;
	float Y;
};

float incline(dot, dot);

int main()
{
	cout << "�� ���� ��ǥ�� �Է����ּ���: " << endl;
	dot A, B;
	cin >> A.X >> A.Y;
	cin >> B.X >> B.Y;

	float incl = incline(A, B);
	if (incl == INT_MAX)
	{
		return 0;
	}
	cout << "����� " << incl << "�Դϴ�." << endl;
	return 0;
}

float incline(dot a, dot b)
{
	if (a.X - b.X == 0)
	{
		cout << "�� ���� ����� �����Դϴ�." << endl;
		return INT_MAX;
	}
	return (a.Y - b.Y) / (a.X - b.X);
}