// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <locale.h>
#include <iostream>

using namespace std;
class test
{
public:
	test() { cout << "생성" << endl; }
	~test() { cout << "삭제" << endl; }
};
#include <iomanip>

int main()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 3)
			break;

		cout << i << endl;
		
	}
	return 0;
}


//
//int str_len2(char src[], char tar[])
//{
//	int k = str_len1(src, tar);
//	if (k == -1)
//		return -1;
//
//	for (int i = 0; i < strlen(tar); i++)
//	{
//		src[k + i] = '*';
//	}
//	return 0;
//}

bool isBetweenPt(POINT target, POINT p1, POINT p2)
{
	int distance1 = PtDistance(target, p1);
	int distance2 = PtDistance(target, p2);
	int distance3 = PtDistance(p1, p2);

	if (distance1 + distance2 == distance3)
		return true;
	else
		return false;
}

int PtDistance(POINT p1, POINT p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}