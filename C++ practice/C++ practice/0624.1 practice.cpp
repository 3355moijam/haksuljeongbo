#include "stdafx.h"

void switchLocker(array<bool, 100> &locker);
void printLocker(array<bool, 100> &locker);

int main()
{
	array<bool,100> locker = { false };
	switchLocker(locker);
	printLocker(locker);
}

void switchLocker(array<bool, 100> &locker)
{
	for (int i = 2; i <= locker.size(); i++)
	{
		for (int j = i; j <= locker.size(); j += i)
		{
			locker[j-1] = !locker[j-1];
		}
	}
}

void printLocker(array<bool, 100> &locker)
{
	for (int i = 0; i < locker.size(); i++)
	{
		if (locker[i])
			cout << i+1 << endl;
	}
}