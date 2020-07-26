#include "stdafx.h"
#include <cmath>

int GaussSum(int n);
int GaussSum(int start, int end);

int main()
{
	cout << "1부터 몇까지 더할까요? :" << endl;
	int n;
	cin >> n;
	cout << GaussSum(n) << endl;


	cout << "몇부터 몇까지 더할까요? :" << endl;
	int a, b;
	cin >> a >> b;
	cout << GaussSum(a, b) << endl;
	return 0;
}

// 가우스 덧셈.
int GaussSum(int n)
{
	return (1 + n) * n / 2;
}

int GaussSum(int start, int end)
{
	return (start + end) * (abs(start - end) + 1) / 2;
}