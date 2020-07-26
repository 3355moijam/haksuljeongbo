#include "stdafx.h"

int main(void)
{
	char szBuffer[12] = { "HelloWorld" };
	char *pszData = NULL;

	pszData = (char *)malloc(sizeof(char) * 12);
	//pszData = szBuffer;
	memcpy(pszData, szBuffer, sizeof(char) * 12);
	//szBuffer[5] = 'X';

	puts(pszData);
	
	free(pszData);

	return 0;
}