// practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>

int main(void)
{
	
	char ch = 0;

	printf("�ƹ� Ű�� ������ �������� �Ѿ�ϴ�. \n");

	ch = _getch();

	printf("�Է��� Ű�� ");
	putchar(ch);
	printf("�Դϴ�. \n");
	

	long long int lldData = 4294967295LL;
	printf("%d\n", lldData);
	printf("%u\n", lldData);

	printf("%u\n", lldData+1);
	printf("%u\n", lldData+2);
	printf("%u\n", lldData+3);

	printf("%lld\n", lldData + 1);
	printf("%lld\n", lldData + 2);
	printf("%lld\n", lldData + 3);

	return 0;
}

