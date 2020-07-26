#include "stdafx.h"

char* mystrcat(char *pszDst, char * pszSrc);

int main(int argc, char* argv[])
{
	//char szPath[128] = { "C:\\Program Files\\" };
	//char szBuffer[128] = { 0 };

	//printf("Input path : ");
	//gets_s(szBuffer);

	//strcat(szPath, szBuffer);
	//puts(szPath);
	/////////////////


	char szPath[128] = { 0 };
	char *pszEnd = NULL;

	

	pszEnd = mystrcat(szPath, "C:\\Program Files\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C Programming");
	
	puts(szPath);

	return 0;
}

char* mystrcat(char *pszDst, char * pszSrc)
{
	while (*pszDst != '\0')
		++pszDst;

	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	*++pszDst = '\0';

	return --pszDst;
}