#include "stdafx.h"

int main(void)
{
	int a99[9][9] = { 0 };

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			a99[i][j] = (i+1) * (j+1);
		}
	}

	printf("¸î´Ü? : ");
	int nInput;
	scanf_s("%d", &nInput);

	printf("\t%d´Ü\n", nInput);
	for (int i = 0; i < 9; i++)
	{
		printf("%2d * %d = %2d\n", nInput, i + 1, a99[nInput - 1][i]);
	}

	return 0;
}