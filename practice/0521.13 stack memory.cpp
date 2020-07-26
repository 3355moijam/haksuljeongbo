#include "stdafx.h"

void PutData(char *pszParam)
{
	if (*pszParam == '\0')
		return;

	putchar(*pszParam);
	PutData(pszParam + 1);
}
int main(int argc, char* argv[])
{
	// 재귀함수는 스택을 쌓아가다 차례로 리턴하는 것.
	PutData("TestData");
	putchar('\n');


	return 0;
}
//
//int InputCount(void)
//{
//	int num;
//	while (1)
//	{
//		printf("몇 번 입력할까요? : ");
//		scanf_s("%d%*c", &num);
//
//		if (num > 0)
//			break;
//		printf("양수를 입력해 주세요.\n");
//	}
//	return num;
//}
//
//int InputNum(int i)
//{
//	printf("입력 %d : ", i);
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
//void MemError(void* arr)
//{
//	printf("메모리 할당에 실패했습니다.\n");
//	free(arr);
//	exit(1);
//}