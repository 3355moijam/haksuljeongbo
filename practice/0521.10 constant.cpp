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
//		printf("�� �� �Է��ұ��? : ");
//		scanf_s("%d%*c", &num);
//
//		if (num > 0)
//			break;
//		printf("����� �Է��� �ּ���.\n");
//	}
//	return num;
//}
//
//int InputNum(int i)
//{
//	printf("�Է� %d : ", i);
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
//void MemError(void* arr)
//{
//	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
//	free(arr);
//	exit(1);
//}