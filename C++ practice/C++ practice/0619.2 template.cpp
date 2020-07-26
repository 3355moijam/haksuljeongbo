#include "stdafx.h"

template <typename T>
void Swap(T &a, T &b);

int main()
{
	int i = 10;
	int j = 20;

	cout << "i , j = " << i << ", " << j << "." << endl;
	cout << "컴파일러가 생성한 int형 교환기를 사용하면" << endl;
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << "." << endl;

	double x = 24.5;
	double y = 81.7;
	cout << "x , y = " << x << ", " << y << "." << endl;
	cout << "컴파일러가 생성한 double형 교환기를 사용하면" << endl;
	Swap(x, y);
	cout << "이제 x, y = " << x << ", " << y << "." << endl;

	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}