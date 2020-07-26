#include "stdafx.h"


int main(int argc, char* argv[])
{
	char szBuffer[128] = { "nData = x + y;\nnResult = a * b" };

	char *pszSep = " *+=;\n";
	char *pszToken = NULL;

	pszToken = strtok(szBuffer, pszSep);
	while (pszToken != NULL)
	{
		puts(pszToken);
		pszToken = strtok(NULL, pszSep); // 인자에 NULL을 넣으면 이어서 토크나이즈함
	}

	printf("\nszBuffer: %s\n", szBuffer);




	return 0;
}