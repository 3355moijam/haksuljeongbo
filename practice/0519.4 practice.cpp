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
		printf("�� �� �Է��ұ��? : ");
		scanf_s("%d%*c", &num);
		
		if (num > 0)
			break;
		printf("����� �Է��� �ּ���.\n");
	}
	return num;
}

int InputNum(int i)
{
	printf("�Է� %d : ", i);
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int* arr, int sum)
{
	printf("�Է¹��� ���� ");
	int length = _msize(arr) / sizeof(int);
	for (int i = 0; i < length-1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d ", arr[length-1]);
	printf("�̰� ���� %d�Դϴ�.\n", sum	);

}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
 }