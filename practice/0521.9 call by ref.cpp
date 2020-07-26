#include "stdafx.h"

int* InitList(int *List, int *nSize);
void SortList(int *List, int *nSize);
void PrintList(int *List, int *nSize);

void Swap(int *a, int *b);
void MemError(void* arr);

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int* pList = (int *)malloc(sizeof(int)*5);
	int nSize = 0;

	pList = InitList(pList, &nSize);
	//printf("%zd\n", _msize(pList));
	SortList(pList, &nSize);
	PrintList(pList, &nSize);

	free(pList);

	_CrtDumpMemoryLeaks();

	return 0;
}

int* InitList(int *List, int *nSize)
{
	//int nInput = 0;
	int *tmp = List;
	while(1)
	{
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%d", &List[*nSize]);
		if (List[*nSize] <= 0)
			break;
		//printf("%d\n", *nSize);
		//List[*nSize] = nInput;
		//printf("%d\n", List[*nSize]);

		List = (int*)realloc(List, (*nSize+2)* sizeof(int)); 
		// �Լ� ������ realloc�ϸ� �̰� ������ ���������
		if (List == NULL)
			MemError(List);
		
		*nSize += 1;
	}

	for(int j = 0; j < *nSize; j++)
		printf("%d\n", List[j]);

	return List;
}

void SortList(int *List, int *nSize)
{
	int i = 0, j = 0;
	
	for (i = 0; i < *nSize - 1; i++)
	{
		for (j = i + 1; j < *nSize; j++)
		{
			Swap(&List[i], &List[j]);
		}
	}
}

void PrintList(int *List, int *nSize)
{
	int i = 0;
	for (i = 0; i < *nSize; i++)
		printf("%d\t", List[i]);
	putchar('\n');
}
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
 }
void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}