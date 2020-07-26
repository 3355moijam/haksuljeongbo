#include "stdafx.h"

int main(void)
{
	int aList[2][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 }
	};
	int i = 0, j = 0;
	// ¿€º∫
	int aRot[4][2] = { 0 };

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			aRot[j][!i] = aList[i][j];
		}

	}

	//>> ≥°
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d\t", aRot[i][j]);

		putchar('\n');
	}
	putchar('\n');
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d\t", aList[i][j]);

		putchar('\n');
	}


	return 0;
}
