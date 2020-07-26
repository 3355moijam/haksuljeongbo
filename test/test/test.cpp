// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <locale.h>
#include <iostream>

using namespace std;

struct dot
{
	int a;
	int b;
};

dot swap(dot x)
{
	int temp = x.a;
	x.a = x.b;
	x.b = temp;

	return x;
}
#include <iomanip>

int main()
{
	char str1[] = "abcdefghi";
	char str2[] = "efg";
	str_len2(str1, str2);
	cout << str1 << endl;
	return 0;
}

int str_len1(char * src, char * tar)
{

}

int str_len2(char src[], char tar[])
{
	int k = str_len1(src, tar);
	if (k == -1)
		return -1;

	for (int i = 0; i < strlen(tar); i++)
	{
		src[k + i] = '*';
	}
	return 0;
}