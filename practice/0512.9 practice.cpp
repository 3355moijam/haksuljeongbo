#include "stdafx.h"

int main(void)
{
	int num1 = 0, sum1 = 0;
	while (num1 < 10) 
	{	
		sum1 += ++num1;
	}
	printf("%d\n", sum1);

	int sum2 = 0;
	for (int num2 = 0; num2 <= 10; num2++)
	{
		sum2 += num2;
	}
	printf("%d\n", sum2);

	return 0;
}
