#include "stdafx.h"

int ABS(int a);
void Print(int num);
int InputNum(void);

int main(void)
{
	Print(ABS(InputNum()));

	return 0;
}

int ABS(int a)
{
	int num = a;
	if (a < 0)
		num *= -1;

	return num;
}

void Print(int num)
{
	printf("���밪�� %d �Դϴ�.\n", num);
}

int InputNum(void)
{
	printf("������ �Է��ϼ��� : ");
	int num;
	scanf_s("%d%*c", &num);
	
	return num;
}