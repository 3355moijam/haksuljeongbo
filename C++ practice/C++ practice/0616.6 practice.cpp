#include "stdafx.h"
#include <cstring>

int main()
{
	char sInput[50]; 
	int countVw = 0;
	int countCons = 0;
	int countOthr = 0;

	do
	{
		cin >> sInput;
		if (isalpha(sInput[0]))
		{
			if (strpbrk(sInput, "aeiouAEIOU") == sInput)
				countVw++;
			else
				countCons++;
		}
		else
		{
			countOthr++;
		}

	} while (strcmp(sInput,"q"));
	countCons--;// q 빼주기

	cout << "모음으로 시작하는 수 : " << countVw << endl;
	cout << "자음으로 시작하는 수 : " << countCons << endl;
	cout << "기타 : " << countOthr << endl;
	return 0;
}
