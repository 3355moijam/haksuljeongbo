#include "stdafx.h"

void Add(double num1, double num2);
void Minus(double num1, double num2);

int main(void)
{
	double x = 3.1, y = 5.5;
	void(*pFunc)(double, double);
	// 함수도 어딘가에 주소를 가지고있음. 그래서 그 주소를 출력해 줄 수 가 있다.

	printf("add' address : %x\n", Add);
	printf("pFunc' address : %x\n", &pFunc);

	pFunc = Add;	// 포인터 변수에 함수를 할당해준것.
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