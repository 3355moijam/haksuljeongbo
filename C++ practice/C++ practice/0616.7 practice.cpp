#include "stdafx.h"

string getPW(void);
bool checkLeng(string);
bool checkNum(string);

int main()
{
	/*
	1. ��й�ȣ�� ��� 8���� ���ڿ��� �Ѵ�.
	2. ��й�ȣ�� ���ڿ� ���ڷθ� �����Ǿ�� �Ѵ�.
	3. ��й�ȣ�� ��� �ΰ��� ���ڰ� ���ԵǾ�� �Ѵ�.
	*/

	string sInput = {};
	
	while (1)
	{
		sInput = getPW();

		if (!checkLeng(sInput))
		{
			cout << "invalid password" << endl;
			continue;
		}
		if (checkNum(sInput))
		{
			cout << "valid password" << endl;
			break;
		}
		else
		{
			cout << "invalid password" << endl;
			continue;
		}
	}
	return 0;
}

string getPW(void)
{
	string tmp;
	cout << "��й�ȣ�� �Է����ּ���. : ";
	cin >> tmp;
	return tmp;
}

bool checkLeng(string input)
{
	return input.length() >= 8;
}

bool checkNum(string input)
{
	int numcount = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (!isalnum(input[i]))
			return false;

		if (isdigit(input[i]))
			numcount++;
	}
	if (numcount++ < 2)
		return false;

	return true;
}