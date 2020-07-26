#include "stdafx.h"
#include <cmath>

int GaussSum(int n);
int GaussSum(int start, int end);

int main()
{
	cout << "1���� ����� ���ұ��? :" << endl;
	int n;
	cin >> n;
	cout << GaussSum(n) << endl;


	cout << "����� ����� ���ұ��? :" << endl;
	int a, b;
	cin >> a >> b;
	cout << GaussSum(a, b) << endl;
	return 0;
}

// ���콺 ����.
int GaussSum(int n)
{
	return (1 + n) * n / 2;
}

int GaussSum(int start, int end)
{
	return (start + end) * (abs(start - end) + 1) / 2;
}