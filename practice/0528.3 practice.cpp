#include "stdafx.h"


void set99(FILE *fp);
int getInput(void);
void Print(FILE *fp, int num);


int main(int argc, char* argv[])
{
	FILE *fp = NULL;
	fp = fopen("99.txt", "w");
	if (fp == NULL)
	{
		printf("ERROR: file open fail");
		return 0;
	}
	
	set99(fp);
	
	fclose(fp);

	int num = getInput();

	fp = fopen("99.txt", "r");
	
	Print(fp, num);

	fclose(fp);

	return 0;
}
void set99(FILE *fp)
{
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			fprintf(fp, "%d x %d = %2d\n", i, j, i*j);
		}
	}
}

int getInput(void)
{
	printf("¸î´Ü? :");
	int num;
	scanf_s("%d", &num);
	rewind(stdin);
	if (num < 2)
		num = 2;
	else if (num > 9)
		num = 9;

	return num;
}

void Print(FILE *fp, int num)
{
	fseek(fp, 12 * 9 * (num - 2), SEEK_SET);
	char szBuffer[256] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		fgets(szBuffer, 256, fp);
		printf("%s", szBuffer);
		memset(szBuffer, 0, 256);
	}
}
