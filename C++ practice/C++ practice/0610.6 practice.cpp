#include "stdafx.h"

int midium(int, int, int);
int midium2(int, int, int);
int main()
{
	cout << "세 수를 입력해주세요 : " << endl;
	int a, b, c;
	cin >> a >> b >> c;
	cout << "중앙값은 " << midium(a, b, c) << endl;
	cout << "중앙값은 " << midium2(a, b, c) << endl;

	return 0;
}

int midium(int a, int b, int c)
{
	int mid;

	if (a >= b)
	{
		if (a > b)
		{
			if (b >= c) // a > b, b >= c
			{
				mid = b;
			}
			else
			{
				if (a >= c)
				{
					mid = c;
				}
				else
				{
					mid = a;
				}
			}
		}
		else // a = b
		{
			mid = b;
		}
	}

	else
	{
		if (a >= c)
		{
			mid = a;
		}
		else
		{
			if (b >= c)
			{
				mid = c;
			}
			else
			{
				mid = b;
			}
		}

	}

	return mid;
}

int midium2(int a, int b, int c)
{
	int mid;
	if (a == b || b == c)
	{
		mid = b;
	}
	else if (a == c)
	{
		mid = a;
	}
	else if (a > b)
	{
		if (b > c)
			mid = b;
		else if (c > a)
			mid = a;
		else mid = c;
	}
	else // b > a
	{
		if (a > c)
			mid = a;
		else if (c > b)
			mid = b;
		else mid = c;
	}

	return mid;
}