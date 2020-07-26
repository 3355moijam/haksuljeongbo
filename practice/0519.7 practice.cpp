#include "stdafx.h"
#include <malloc.h>
#include <crtdbg.h>

int InputNum(int i);
void Print(int* arr, int len, int sum);
void solution(void);
int* ArrayExtend(int *arr);

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	solution();

	_CrtDumpMemoryLeaks();

	return 0;
}
void solution(void)
{
	int nCount = 1, sum = 0, nInput;

	int *paList = (int*)calloc(5, sizeof(int));  

	while (1)
	{
		nInput = InputNum(nCount);
		if (nInput == -1)
			break;

		if (_msize(paList) / sizeof(int) < nCount)  // �迭 ũ�⺸�� �Էµ� ������ �� ���� ��� Ȯ��.
		{
			paList = ArrayExtend(paList);
		}

		paList[nCount - 1] = nInput;
		sum += paList[nCount - 1];
		nCount++;
	}

	Print(paList, nCount - 1, sum);

	if(paList != NULL)
		free(paList);
}

int* ArrayExtend(int *arr)
{
	int len = _msize(arr) / sizeof(int);
	int *tmpList = (int*)calloc(len+5, sizeof(int));
	memcpy(tmpList, arr, sizeof(int) * len);
	free(arr);

	return tmpList;
}

int InputNum(int i)
{
	printf("�Է� %d : ", i);
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int* arr, int len, int sum)
{
	printf("�Է¹��� ���� ");
	for (int i = 0; i < len - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	if (len > 0)
		printf("%d ", arr[len - 1]);
	else
		printf("%d ", arr[0]);
	printf("�̰� ���� %d�Դϴ�.\n", sum);

}
