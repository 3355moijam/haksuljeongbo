#include "stdafx.h"

void solution(void);
int InputArray(void);
int InputIJ(void);
long long GetArray(int n, int r, int c);
void Print(int n, int r, int c, long long nAnswer);
void Debug(int n);

int main(void)
{

	solution();

	return 0;
}

void solution(void)
{
	int n = InputArray();
	int r = InputIJ();
	int c = InputIJ();
	long long nAnswer = GetArray(n, r, c);

	// debug
	Debug(n);

	Print(n, r, c, nAnswer);
}

long long GetArray(int n, int r, int c)
{
	long long nAnswer = 0LL;
	int i = 0, j = 1, linecontrol = 0;
	for (int line = 1; line <= 2*n-1; line++)
	{
		if (line <= n)
		{
			linecontrol = line;
		}
		else
		{
			linecontrol = 2 * n - line;
		}

		for (int k = 0; k < linecontrol; k++)
		{
			if (k == 0 && line <= n)
			{  // 벽에 부딪쳤고, 절반을 넘지 않은 상황에서 i,j의 증감
				if (line % 2 == 1)
				{
					i++;
				}

				else
				{
					j++;
				}
			}
			else if (k == 0 && line > n)
			{  // 벽에 부딪쳤고, 절반을 넘은 상황에서 i,j의 증감
				if (line % 2 == 1)
				{
					j++;
				}

				else
				{
					i++;
				}
			}
			else
			{  // 벽에 부딪치지 않은 상황에서 i,j의 증감
				if (line % 2 == 1)
				{
					i--;
					j++;
				}

				else
				{
					i++;
					j--;
				}
			}
			nAnswer++;
				
			if (i == r && j == c)
				return nAnswer;
		}
	}

	printf("잘못된 값이 입력되었습니다.\n");
	return 0;
}

int InputArray(void)
{
	printf("n 사각 행렬 : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

int InputIJ(void)
{
	printf("r행 c열 : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int n, int r, int c, long long nAnswer)
{
	printf("%d*%d 사각 행렬의 %d행 %d열 : %lld\n", n, n, r, c, nAnswer);
}

void Debug(int n)
{
	printf("\n\n\n");

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%5lld ", GetArray(n, i, j));
		}
		printf("\n\n\n");
	}
}