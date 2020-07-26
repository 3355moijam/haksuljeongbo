#include "stdafx.h"

template <typename T>
void Swap(T &a, T &b);

int main()
{
	int i = 10;
	int j = 20;

	cout << "i , j = " << i << ", " << j << "." << endl;
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�" << endl;
	Swap(i, j);
	cout << "���� i, j = " << i << ", " << j << "." << endl;

	double x = 24.5;
	double y = 81.7;
	cout << "x , y = " << x << ", " << y << "." << endl;
	cout << "�����Ϸ��� ������ double�� ��ȯ�⸦ ����ϸ�" << endl;
	Swap(x, y);
	cout << "���� x, y = " << x << ", " << y << "." << endl;

	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}