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
		pszToken = strtok(NULL, pszSep); // ���ڿ� NULL�� ������ �̾ ��ũ��������
	}

	printf("\nszBuffer: %s\n", szBuffer);




	return 0;
}