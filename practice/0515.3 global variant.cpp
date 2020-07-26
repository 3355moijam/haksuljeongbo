#include "stdafx.h"

void InitList(int *pList, int nSize);
void SortList(int *pList, int nSize);
void PrintList(int *pList, int nSize);

int main(void)
{
	int aList[5] = { 0 };

	InitList(aList, 5);
	SortList(aList, 5);
	PrintList(aList, 5);

	return 0;
}

void InitList(int *pList, int nSize)
{
	int i = 0;
	for (i = 0; i < nSize; i++)
	{
		printf("정수를 입력하세요. : ");
		scanf_s("%d", &pList[i]);
	}
}

void SortList(int *pList, int nSize)
{
	int i = 0, j = 0, nTmp = 0;

	for (i = 0; i < nSize - 1; i++)
	{
		for(j = i + 1; j < nSize; j++)
		{
			if (pList[j] < pList[i])
			{
				nTmp = pList[i];
				pList[i] = pList[j];
				pList[j] = nTmp;
			}
		}
	}
}

void PrintList(int *pList, int nSize)
{
	int i = 0;
	for (i = 0; i < nSize; i++)
	{
		printf("%d\t", pList[i]);
	}
	putchar('\n');
}
