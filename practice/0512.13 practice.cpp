#include "stdafx.h"

int main(void)
{
	/*for (int i = 1; i <= 9; i++)
	{
		if (i < 6)
		{
			for (int j = 0; j < 5 - i; j++)
				printf("\t ");

			for (int k = 0; k < 2 * i - 1; k++)
				printf("\t*");

			printf("\n");
		}

		else
		{
			for (int j = 0; j < i - 5; j++)
				printf("\t ");

			for (int k = 0; k < 19 - 2 * i; k++)
				printf("\t*");

			printf("\n");
		}
	}*/
	////////////////////////////////////
	int input;
	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
	{
			for (int j = 0; j < input - i; j++)
				printf("\t ");

			for (int k = 0; k < 2 * i - 1; k++)
				printf("\t*");

			printf("\n");	
	}

	for (int i = input -1; i > 0; i--)
	{
		for (int j = 0; j < input - i; j++)
			printf("\t ");

		for (int k = 0; k < 2 * i - 1; k++)
			printf("\t*");

		printf("\n");
	}
	return 0;
}
