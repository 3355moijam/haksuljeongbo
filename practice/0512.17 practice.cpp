#include "stdafx.h"

int main(void)
{
	int num1 = 2, num2 = 3, num3 = 4;
	while(1)
	{
		if (num3 < 9)
		{
			printf("\t%d\t\t%d\t\t%d\t\n", num1, num2, num3);
			printf("---------------------------------------------------\n");

			for (int i = 1; i <= 9; i++)
				printf("     %d*%d= %2d\t     %d*%d= %2d\t     %d*%d= %2d \n", num1, i, num1*i, num2, i, num2*i, num3, i, num3*i);
			printf("\n");
			num1 += 3;
			num2 += 3;
			num3 += 3;
		}
		else
		{
			printf("\t%d\t\t%d\t\n", num1, num2);
			printf("----------------------------------\n");
			for (int i = 1; i <= 9; i++)
				printf("     %d*%d= %2d\t     %d*%d= %2d \n", num1, i, num1*i, num2, i, num2*i);
			printf("\n");
			break;
		}

		
	}

	return 0;
}
