#include "stdafx.h"

int Fibonacci(int num);
int InputNum(void);
void Print(int num);

int main(void)
{
	while (1)
	{
		Print(Fibonacci(InputNum()));
	}

	return 0;
}

int Fibonacci(int num)
{
	if (num < 1)
		return 0;
	else if (num == 1)
		return 1;
	else
		return Fibonacci(num - 1) + Fibonacci(num - 2);

}

int InputNum(void)
{
	printf("�� ������ ��������? : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int num)
{
	printf("�����̴� %d���� �Դϴ�.\n", num);
}