#include "stdafx.h"
#include <malloc.h>

int InputNum(int i);
int InputCount(void);
void Print(int* arr, int sum);
void Swap(int *a, int *b);

int main(void)
{
	int nCount = InputCount(), sum = 0;

	int *paList = (int*)malloc(sizeof(int) * nCount);

	for (int i = 0; i < nCount; i++)
	{
		paList[i] = InputNum(i + 1);
		sum += paList[i];
	}

	Print(paList, sum);

	free(paList);

	return 0;
}

int InputCount(void)
{
	int num;
	while (1)
	{
		printf("몇 번 입력할까요? : ");
		scanf_s("%d%*c", &num);
		
		if (num > 0)
			break;
		printf("양수를 입력해 주세요.\n");
	}
	return num;
}

int InputNum(int i)
{
	printf("입력 %d : ", i);
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int* arr, int sum)
{
	printf("입력받은 수는 ");
	int length = _msize(arr) / sizeof(int);
	for (int i = 0; i < length-1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d ", arr[length-1]);
	printf("이고 합은 %d입니다.\n", sum	);

}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
 }