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
	countCons--;// q ���ֱ�

	cout << "�������� �����ϴ� �� : " << countVw << endl;
	cout << "�������� �����ϴ� �� : " << countCons << endl;
	cout << "��Ÿ : " << countOthr << endl;
	return 0;
}
