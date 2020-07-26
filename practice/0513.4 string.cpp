#include "stdafx.h"

int main(void)
{
	//int aList[5] = { 30, 40, 10, 50, 20 };
	//char szBuffer[6] = { 'H','e','l','l','o','\0' };

	//char szData[8] = { "Hello" };
	//char *pszBuffer = "Hello";

	//puts(szBuffer);
	//puts(szData);
	//puts(pszBuffer);
	////////////////////////

	char szBuffer[32] = { 0 };
	int nLength = 0;

	printf("Input your name : ");
	gets_s(szBuffer);

	while (szBuffer[nLength] != '\0')
		nLength++;

	printf("Your name is %s(%d).\n", szBuffer, nLength);

	return 0;
}
