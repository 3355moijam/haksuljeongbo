#include "stdafx.h"


int main(int argc, char* argv[])
{
	// strpbrk �˻��� ���ڿ��� �ִ� ���ڵ� �� �ϳ��� �ִ��� �˻�. 
	// "ABC"�� ������ A, B, C �� �ϳ��� �ִ��� �˻��Ѵ�.
	

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
