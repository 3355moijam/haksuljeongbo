#include "stdafx.h"
//
//int InputNum(void);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	// void* malloc(size) size는 할당할 메모리 바이트 크기
	// void free(void* memblock) malloc을 썼으면 반드시 사용. 메모리를 비우는 함수. memblock은 반환할 메모리 주소.
	// free가 제대로 안되면 메모리 누수가 발생

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

	// memset(초기화할 메모리, 초기값(0), 초기화할 메모리의 크기(byte)  메모리값 초기화
	// calloc(요소의 개수, 요소의 크기)  malloc + memset

	int *pList = NULL, *pNewList = NULL;

	int aList[3] = { 0 };

	pList = (int*)malloc(sizeof(int) * 3);  // 초기화를 안하면 쓰레기값이 나옴
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
//	printf("몇 개월이 지났나요? : ");
//	int num;
//	scanf_s("%d%*c", &num);
//
//	return num;
//}
//
//void Print(int num)
//{
//	printf("달팽이는 %d마리 입니다.\n", num);
//}
//
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
// }