#include "stdafx.h"

void Print(int len);
void solution(void);
int InputNum(void);
void MakeArray(int len);
void ArrayCross(int len);

#define SIZE 50
int g_aList[SIZE][SIZE] = { 0 };
int g_aNewList[SIZE][SIZE] = { 0 };

int main(void)
{

	solution();

	return 0;
}

void solution(void)
{
	int length = InputNum();

	MakeArray(length);
	ArrayCross(length);

	Print(length);
}

void ArrayCross(int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				g_aNewList[i][j] += g_aList[i][k];
				g_aNewList[i][j] += g_aList[k][j];
			}
			g_aNewList[i][j] -= g_aList[i][j];
		}
	}
}

void MakeArray(int len)
{
	int count = 0;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			g_aList[i][j] = ++count;
		}
	}
}

int InputNum(void)
{
	printf("Á¤¼ö 3~50 : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf("%5d ", g_aNewList[i][j]);
		}
		printf("\n");
	}
}

