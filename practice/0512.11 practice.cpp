#include "stdafx.h"

int main(void)
{
	printf("n! :");
	int n;
	double fact = 1;
	
	scanf_s("%d", &n);
	if (n >= 1)
	{
		for (int i = 1; i <= n; i++)
		{
			fact *= i;
		}
		printf("%.0f\n", fact);
	}
	else
		printf("��������� ���ǵ˴ϴ�\n");


	return 0;
}
