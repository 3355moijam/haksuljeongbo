#include "stdafx.h"


int main(void)
{
	int aList[5] = { 30, 40, 10, 50, 20 };
	int nListLeng = sizeof(aList) / sizeof(int);
	// 초기 배열
	printf("초기 : ");
	for (int i = 0; i < nListLeng; i++)
	{
		printf("%d ", aList[i]);
	}
	printf("\n\n\n");
	
	//// 선택정렬로 알려진 버블정렬(?) 오름차순. 선택정렬에 가까움. 1부터 끝까지 비교, 2부터 끝까지 비교 해나가며 정렬
	//for (int i = 0; i < nListLeng-1; i++)
	//{
	//	for (int j = i + 1; j < nListLeng; j++)
	//	{
	//		if (aList[i] > aList[j])
	//		{
	//			int tmp = aList[i];
	//			aList[i] = aList[j];
	//			aList[j] = tmp;
	//		}
	//	}
	//}
	////////////////

	// 버블정렬 1과2, 2와3, 3과4 ... n-1과 n을 비교하여 교환. n-1번 반복
	//for (int i = 0; i < nListLeng - 1; i++)
	//{
	//	for (int j = 0; j < nListLeng - 1; j++)
	//	{
	//		if (aList[j] > aList[j+1])
	//		{
	//			int tmp = aList[j];
	//			aList[j] = aList[j+1];
	//			aList[j+1] = tmp;
	//		}
	//	}
	//}
	//////////////////////////////////////

	// 선택정렬. 순차적으로 비교하다 가장 작/크다는걸 확인하고 나서 단 한 번만 교환한다.
	int index = 0;
	for (int i = 0; i < nListLeng - 1; i++)
	{
		index = i;
		for (int j = i+1; j < nListLeng; j++)
		{
			if (aList[index] > aList[j])
			{
				index = j;
			}
		}
		int tmp = aList[i];
		aList[i] = aList[index];
		aList[index] = tmp;

		// 변화추적
		for (int i = 0; i < nListLeng; i++)
		{
			printf("%d ", aList[i]);
		}
		printf("\n\n");
	}
	////////////////////////////////////


	// 출력부분
	printf("\n결과 : ");
	for (int i = 0; i < nListLeng; i++)
	{
		printf("%d ", aList[i]);
	}
	printf("\n\n");




	return 0;
}

