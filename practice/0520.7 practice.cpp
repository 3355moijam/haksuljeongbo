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
			printf("��\n");
	}


	return 0;
}


int InputNum(void)
{
	printf("���ڸ� �Է����ּ��� : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void MemError(void)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	exit(1);
}

void BubSort(int *arr, int count)	//��������
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

void SelSort(int* arr, int count)  // ��������
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

void Print(int* arr, int len, bool i = false)	// false ��������, true ��������
{
	if (i)
		printf("Selection(��������): ");
	else
		printf("Bubble(��������): ");

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