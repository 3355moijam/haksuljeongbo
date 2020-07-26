#include "stdafx.h"

int main(void)
{
	int aList[5][5] = { 0 }, count = 0;
	bool check = true;

	// �汝鶬� 牖ч, 礎熱還 羲ч
	for (int i = 0; i < 5; i++)
	{
		if (check)
		{
			for (int j = 0; j < 5; j++)
			{
				count++;
				aList[j][i] = count;
			}
		}

		else
		{
			for (int j = 4; j >= 0; j--)
			{
				count++;
				aList[j][i] = count;
			}
		}

		check = !check;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", aList[i][j]);
		}
		printf("\n\n");
	}
}
