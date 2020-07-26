#include "stdafx.h"

void nrpira(int n);

int main()
{
	cout << "양의 정수 입력 : ";
	int nInput;
	cin >> nInput;

	nrpira(nInput);

	return 0;
}

void nrpira(int n)
{
	int odd = 2 * n - 1;
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		for (int j = 0; j < i - 1; j++)
			cout << " ";
		for (int j = 0; j < odd - 2 * (i-1); j++)
			cout << i % 10;

		cout << endl;
	}

	for (i = n-1; i >= 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
			cout << " ";
		for (int j = 0; j < odd - 2 * (i - 1); j++)
			cout << i % 10;

		cout << endl;
	}
}