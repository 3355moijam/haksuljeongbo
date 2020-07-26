#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//void MemError(void* arr);
//
int GetLength(const char *pszParam)
{
	int nLength = 0;

	//*pszParam = "Love Live";

	while (pszParam[nLength] != '\0')
		nLength++;

	return nLength;

}
int main(int argc, char* argv[])
{
	
	char * pszData = "Hello";

	printf("%d\n", GetLength("Hi"));
	printf("%d\n", GetLength("pszData"));


	return 0;
}

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