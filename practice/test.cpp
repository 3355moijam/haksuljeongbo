#include "stdafx.h"

int UclidAL(int num1, int num2);

int main(void)
{

	

	printf("%d\n", UclidAL(3000, 4000));

	return 0;
}

int UclidAL(int num1, int num2)
{
	int num3 = num1 % num2;

	if (num3 == 0)
		return num2;
	else
		return UclidAL(num2, num3);

}