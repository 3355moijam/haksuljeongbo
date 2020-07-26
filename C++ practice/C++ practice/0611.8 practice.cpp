#include "stdafx.h"

int digit(unsigned int n);
int digit2(unsigned int n);

int main()
{
	unsigned int nInput;
	cout << "양의 정수를 입력 :";
	cin >> nInput;

	cout << digit(nInput) << endl;
	cout << digit2(nInput) << endl;

	return 0;
}

int digit(unsigned int n)
{
	if (n > 0 && n <= 9)
		return 1;
	else
	{
		return digit(n / 10) + 1;
	}
}

int digit2(unsigned int n)
{
	int i = 0;
	do
	{
		n /= 10;
		i++;
	} while (n != 0);
	return i;
}