#include "stdafx.h"
#include <string.h>
//
//int InputNum(void);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer;
	//int nLength = 0;

	//while (*pszData != '\0')
	//{
	//	pszData++;
	//	nLength++;
	//}

	//printf("Length : %d\n", nLength);
	//printf("Length : %d\n", strlen(szBuffer));
	//printf("Length : %d\n", strlen("World"));
	////////////////////////////

	while (*pszData != '\0')
	{
		pszData++;
	}

	printf("Length : %d\n", pszData - szBuffer);  // null이 저장된 위치 - 시작위치 = 길이
	///////////////////////////


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