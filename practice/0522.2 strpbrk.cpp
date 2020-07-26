#include "stdafx.h"


int main(int argc, char* argv[])
{
	// strpbrk 검색한 문자열에 있는 문자들 중 하나가 있는지 검색. 
	// "ABC"를 넣으면 A, B, C 중 하나가 있는지 검색한다.
	

	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char *pszStart = szBuffer;

	printf("Input String: ");
	gets_s(szBuffer);

	printf("Input character set: ");
	gets_s(szSet);

	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)
	{
		printf("[%p] Index : %d, %c\n", pszStart, pszStart - szBuffer, *pszStart);

		pszStart++;
	}

	return 0;
}
