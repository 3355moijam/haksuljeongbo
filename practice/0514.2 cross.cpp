#include "stdafx.h"
#include <Windows.h>

int main(void)
{
	int aList[10][10] = { 0 }, count = 0;
	bool check = true;

	// È¦¼öÁÙ ¼øÇà, Â¦¼öÁÙ ¿ªÇà
	/*for (int i = 0; i < 5; i++)  
	{
		if (check)
		{
			for (int j = 0; j < 5; j++)
			{
				count++;
				aList[i][j] = count;
			}
		}

		else
		{
			for (int j = 4; j >= 0; j--)
			{
				count++;
				aList[i][j] = count;
			}
		}

		check = !check;
	}*/

	//È¦¼öÁÙ ¼øÇà, Â¦¼öÁÙ ¿ªÇà 2
	/*
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			count++;
			if (!check)
			{
				aList[i][4-j] = count;
			}
			else
			{
				aList[i][j] = count;
			}
		}
		check = !check;
	}*/




	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		printf("%2d ", aList[i][j]);
	//	}
	//	printf("\n\n");
	//}
	return 0;
}
