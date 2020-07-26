#include "stdafx.h"

int main(void)
{
	//int aList[5] = { 30, 40, 10, 50, 20 };
	//int i = 0;
	//// 수정 가능구간

	//for (i = 1; i < 5; i++)
	//{
	//	if (aList[0] < aList[i])
	//	{
	//		aList[0] = aList[i];
	//	}
	//}

	////>>끝
	//for (i = 0; i < 5; i++)
	//	printf("%d\t", aList[i]);

	//putchar('\n');

	//printf("MAX: %d\n\n", aList[0]);
	/////////////////////////////////////

	//int aList[5] = { 30, 40, 10, 50, 20 };
	//int i = 0, nTmp = 0;
	//// 수정 가능구간

	//for (i = 1; i < 5; i++)
	//{
	//	if (aList[0] > aList[i])
	//	{
	//		nTmp = aList[0];
	//		aList[0] = aList[i];
	//		aList[i] = nTmp;
	//	}
	//}

	////>>끝
	//for (i = 0; i < 5; i++)
	//	printf("%d\t", aList[i]);

	//putchar('\n');

	//printf("MIN: %d\n\n", aList[0]);
	/////////////////////////////////////

	int aList[7] = { 0 };
	int max = 0, min = 0, sum = 0;

	printf("7개의 정수를 입력 : ");

	
	for (int i = 0; i < 7; i++)
	{
		scanf_s("%d", &aList[i]);
		if (i == 0)
		{
			max = aList[i];
			min = aList[i];
		}

		else
		{
			if (max < aList[i])
				max = aList[i];
			if (min > aList[i])
				min = aList[i];
		}

		sum += aList[i];
	}

	printf("Min : %d\n", min);
	printf("Max : %d\n", max);
	printf("Sum : %d\n", sum);

	



	return 0;
}
