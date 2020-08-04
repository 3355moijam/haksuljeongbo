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
	long num = -180240;
	num = num >> 5;
	cout << num << endl;

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