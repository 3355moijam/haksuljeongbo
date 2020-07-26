#include "stdafx.h"

int main(void)
{
	int aList[5][5] = { 0 }, count = 0, length = 5;
	int i = 0, j = 5, n = 0;

	while (n < 2 * length - 1)
	{
		for (int k = 0; k < (2 * length - n) / 2; k++)
		{
			if		(n % 4 == 0)	j--;
			else if (n % 4 == 1)	i++;
			else if (n % 4 == 2)	j++;
			else					i--;
			
			aList[i][j] = ++count;
		}
		n++;
	}
	// Ãâ·Â
	for (int a = 0; a < length; a++)
	{
		for (int b = 0; b < length; b++)
			printf("%2d ", aList[a][b]);
		printf("\n\n");
	}
	return 0;
}