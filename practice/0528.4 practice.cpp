#include "stdafx.h"

int main(int argc, char* argv[])
{

	FILE *fp = NULL;
	fp = fopen("TestFile.txt", "a");
	
	char szBuffer[256] = { 0 };
	gets_s(szBuffer, 256);

	fseek(fp, 0, SEEK_END);  // 없어도 맨 끝으로 가지만 혹시 모르니 해주자.
	fprintf(fp, "%s", szBuffer);

	fclose(fp);

	return 0;
}