#include "stdafx.h"

string getPW(void);
bool checkLeng(string);
bool checkNum(string);

int main()
{
	/*
	1. 비밀번호는 적어도 8개의 문자여야 한다.
	2. 비밀번호는 문자와 숫자로만 구성되어야 한다.
	3. 비밀번호는 적어도 두개의 숫자가 포함되어야 한다.
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
	cout << "비밀번호를 입력해주세요. : ";
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