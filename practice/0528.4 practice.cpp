#include "stdafx.h"

int main(int argc, char* argv[])
{

	FILE *fp = NULL;
	fp = fopen("TestFile.txt", "a");
	
	char szBuffer[256] = { 0 };
	gets_s(szBuffer, 256);

	fseek(fp, 0, SEEK_END);  // ��� �� ������ ������ Ȥ�� �𸣴� ������.
	fprintf(fp, "%s", szBuffer);

	fclose(fp);

	return 0;
}