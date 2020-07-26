#include "stdafx.h"

int LeapYear(unsigned int);

int main()
{
	cout << "지금은 몇년인가요? : ";
	unsigned int year;
	cin >> year;
	
	LeapYear(year);

	return 0;
}


int LeapYear(unsigned int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		cout << year << "년은 윤년입니다." << endl;
		return 1;
	}
	else
	{
		cout << year << "년은 윤년이 아닙니다." << endl;
		return 0;
	}
}