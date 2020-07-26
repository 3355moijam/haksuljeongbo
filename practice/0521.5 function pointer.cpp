#include "stdafx.h"

void Add(double num1, double num2);
void Minus(double num1, double num2);

int main(void)
{
	double x = 3.1, y = 5.5;
	void(*pFunc)(double, double);
	// �Լ��� ��򰡿� �ּҸ� ����������. �׷��� �� �ּҸ� ����� �� �� �� �ִ�.

	printf("add' address : %x\n", Add);
	printf("pFunc' address : %x\n", &pFunc);

	pFunc = Add;	// ������ ������ �Լ��� �Ҵ����ذ�.
	pFunc(x, y);

	pFunc = Minus;
	pFunc(x, y);

	return 0;
}

void Add(double num1, double num2)
{
	double result;
	result = num1 + num2;
	printf(" %lf + %lf = %lf \n", num1, num2, result);
}

void Minus(double num1, double num2)
{
	double result;
	result = num1 - num2;
	printf(" %lf + %lf = %lf \n", num1, num2, result);
}