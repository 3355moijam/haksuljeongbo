#include "stdafx.h"
//
//int InputNum(void);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	// void* malloc(size) size�� �Ҵ��� �޸� ����Ʈ ũ��
	// void free(void* memblock) malloc�� ������ �ݵ�� ���. �޸𸮸� ���� �Լ�. memblock�� ��ȯ�� �޸� �ּ�.
	// free�� ����� �ȵǸ� �޸� ������ �߻�

	/*int *pList = NULL, i = 0;
	pList = (int*)malloc(sizeof(int) * 3);
	
	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (; i < 3; i++)
	{
		printf("%d\n", pList[i]);
	}

	free(pList);*/
	///////////////////

	// memset(�ʱ�ȭ�� �޸�, �ʱⰪ(0), �ʱ�ȭ�� �޸��� ũ��(byte)  �޸𸮰� �ʱ�ȭ
	// calloc(����� ����, ����� ũ��)  malloc + memset

	int *pList = NULL, *pNewList = NULL;

	int aList[3] = { 0 };

	pList = (int*)malloc(sizeof(int) * 3);  // �ʱ�ȭ�� ���ϸ� �����Ⱚ�� ����
	for (int i = 0; i < 3; i++)
		printf("%d\n", pList[i]);
	
	memset(pList, 0, sizeof(int) * 3);
	for (int i = 0; i < 3; i++)
		printf("%d\n", pList[i]);

	pNewList = (int*)calloc(3, sizeof(int));
	for (int i = 0; i < 3; i++)
		printf("%d\n", pNewList[i]);

	free(pList);
	free(pNewList);

	return 0;
}
//
//int InputNum(void)
//{
//	printf("�� ������ ��������? : ");
//	int num;
//	scanf_s("%d%*c", &num);
//
//	return num;
//}
//
//void Print(int num)
//{
//	printf("�����̴� %d���� �Դϴ�.\n", num);
//}
//
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
// }