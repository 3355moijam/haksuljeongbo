#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	char szBuffer[32] = { "I am a boy." };

	printf("%p\n", szBuffer);

	printf("%p\n", strstr(szBuffer, "am"));		// 문자열을 검색하고 찾은 위치(주소)를 출력
	printf("%p\n", strstr(szBuffer, "boy"));

	printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);		// 찾은 주소 - 시작주소 해주면 문자열의 인덱스가 나옴.
	printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);

	char *pszBuffer = szBuffer;
	int index = 0;
	if(strstr(szBuffer, "boy") != NULL)
		index = strstr(szBuffer, "boy") - szBuffer;
	

	memcpy(szBuffer+index, "cat", 3);		// boy를 cat으로 치환
	printf("%s\n", szBuffer);
	printf("%s\n", szBuffer+index+3);
	//memcpy(pszBuffer, szBuffer, 5);
	printf("%s\n", pszBuffer);
	///////////////////////////////////


	//char szBuffer[32] = { "You are a girl." };

	//// 전부 같음
	//printf("%c\n", szBuffer[0]);
	//printf("%c\n", *szBuffer);
	//printf("%c\n", *(szBuffer+0));

	//// 전부 같음
	//printf("%c\n", szBuffer[5]);
	//printf("%c\n", *(szBuffer + 5));

	//// 전부 같음
	//printf("%s\n", &szBuffer[4]);
	//printf("%s\n", &*(szBuffer + 4));
	//printf("%s\n", szBuffer + 4);
	////////////////////////////

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