#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	// memcmp(buf1, buf2, count) 두 메모리를 주어진 길이만큼 비교하는 함수	
	// 같으면 0, 양수면 buf1 > buf2, 음수면 buf1 < buf2
	// 같을 때 1이 아니라 0인 것에 주의

	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));		// 저장된 값이 같은 경우
	printf("%d\n", memcmp("teststring", pszData, 10));	// 소문자인 경우
	printf("%d\n", memcmp("DataString", pszData, 10));	// 길이가 같은 경우


	printf("%d\n", szBuffer == pszData);		// 이건 값이 저장된 메모리 주소를 비교하는 것.
	printf("%d\n", "TestString" == pszData);
	printf("%d\n", "Test" == pszData);

	printf("%d\n", strcmp(szBuffer, pszData));		// 문자열을 비교하는 함수. memcmp는 길이가 달라도 일치하는 부분이 있을 수 있지만 이건 길이가 다르면 그냥 다른것.
	printf("%d\n", strcmp("teststring", pszData));
	printf("%d\n", strcmp("DataString", pszData));


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