#include "stdafx.h"
#include <Windows.h>

void getInput(char *src, char *target);
long getFileSize(FILE *fp);
void filecpy(FILE *src, FILE *target);
void Print(long size, long cpy);


const int g_unit = 4096;	// 4kb씩 전송

int main(int argc, char* argv[])
{

	FILE *src = NULL;
	FILE *target = NULL;
	char srcName[256] = { 0 };
	char targetName[256];
	getInput(srcName, targetName);

	
	src = fopen(srcName, "rb");
	if (src == NULL)
	{
		printf("ERROR: src file open fail\n");
		return 0;
	}
	target = fopen(targetName, "wb");
	if (target == NULL)
	{
		printf("ERROR: target file open fail\n");
		return 0;
	}


	filecpy(src, target);


	fclose(src);
	fclose(target);

	return 0;
}

void filecpy(FILE *src, FILE *target)
{
	

	long srcSize = getFileSize(src);
	fseek(src, 0, SEEK_SET);
	fseek(target, 0, SEEK_SET);

	char *szBuffer = (char*)malloc(g_unit);
	for (long i = 0; i < srcSize / g_unit; i++)
	{
		fread(szBuffer, g_unit, 1, src);
		fwrite(szBuffer, g_unit, 1, target);
		memset(szBuffer, 0, g_unit);
		
		if (i % 100 == 0)
		{
			Print(srcSize, g_unit * i);
		}
	}
	if (srcSize % g_unit != 0)
	{
		fread(szBuffer, srcSize % g_unit, 1, src);
		fwrite(szBuffer, srcSize % g_unit, 1, target);
		memset(szBuffer, 0, g_unit);
		
		Print(srcSize, srcSize);
	}
}

long getFileSize(FILE *fp)
{
	fseek(fp, 0, SEEK_END);
	long tmp = ftell(fp);
	return tmp;
}
void getInput(char *src, char *target)
{
	printf("복사할 파일: ");
	gets_s(src, 256);

	char *index = strstr(src, ".");
	sprintf(target, "%s%s", "Dest", index);
}

void Print(long size, long cpy)
{
	system("cls");
	printf("Now Copy : %ldbyte / %ldbyte\n", cpy, size);
	Sleep(30);
}
