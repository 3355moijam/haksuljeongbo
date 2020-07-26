#include "stdafx.h"
//#include <Windows.h>


int InputNum(void);
void BubSort(int* arr, int count);
void SelSort(int* arr, int count);
void MemError(void);
void Swap(int *a, int *b);
void Print(int* arr, int len, bool i);

int main(void)
{
	int *aNum = (int*)malloc(sizeof(int));
	int *aNewNum = NULL;
	int nNum = 0, count = 0;
	int len = 0;

	while (1)
	{
		nNum = InputNum();
		//len = _msize(aNum) / sizeof(int);

		//if ( len < count)
		//{
		//	//free(aNewNum);
		//}

		aNum[count++] = nNum;
		//count++;

		//BubSort(aNum, count);
		//Print(aNum, count, false);
		//SelSort(aNum, count);
		//Print(aNum, count, true);

		aNewNum = (int*)realloc(aNum, sizeof(int)*(count+1));
		if (aNewNum == NULL)
			printf("뻥\n");
	}


	return 0;
}


int InputNum(void)
{
	printf("숫자를 입력해주세요 : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void MemError(void)
{
	printf("메모리 할당에 실패했습니다.\n");
	exit(1);
}

void BubSort(int *arr, int count)	//오름차순
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void SelSort(int* arr, int count)  // 내림차순
{
	int index = 0;
	for (int i = 0; i < count - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < count; j++)
		{
			if (arr[index] < arr[j])
			{
				index = j;
			}
		}
		Swap(&arr[i], &arr[index]);
	}
}

void Print(int* arr, int len, bool i = false)	// false 오름차순, true 내림차순
{
	if (i)
		printf("Selection(내림차순): ");
	else
		printf("Bubble(오름차순): ");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}