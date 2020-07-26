#include "stdafx.h"

int GetData(void);
int GetMax(int num1, int num2, int num3);
void PrintData(int num1, int num2, int num3, int max);

int main(void)
{
	int aList[3] = { 0 };
	int nMax = 0, i = 0;

	for (i = 0; i < 3; i++)
		aList[i] = GetData();

	nMax = GetMax(aList[0], aList[1], aList[2]);

	PrintData(aList[0], aList[1], aList[2], nMax);


	return 0;
}

int GetData(void)
{
	printf("정수를 입력하세요. : ");
	int input;
	scanf_s("%d%*c", &input);

	return input;
}

int GetMax(int num1, int num2, int num3)
{
	int nMax = num1;
	if (nMax < num2)
		nMax = num2;
	if (nMax < num3)
		nMax = num3;

	return nMax;
}

void PrintData(int num1, int num2, int num3, int max)
{
	printf("%d, %d, %d 중 가장 큰 수는 %d 입니다.\n", num1, num2, num3, max);
}