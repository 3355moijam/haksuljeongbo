#include "stdafx.h"

int LeapYear(unsigned int);

int main()
{
	cout << "������ ����ΰ���? : ";
	unsigned int year;
	cin >> year;
	
	LeapYear(year);

	return 0;
}


int LeapYear(unsigned int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		cout << year << "���� �����Դϴ�." << endl;
		return 1;
	}
	else
	{
		cout << year << "���� ������ �ƴմϴ�." << endl;
		return 0;
	}
}