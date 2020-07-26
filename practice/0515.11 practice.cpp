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
			{  // ���� �ε��ư�, ������ ���� ���� ��Ȳ���� i,j�� ����
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
			{  // ���� �ε��ư�, ������ ���� ��Ȳ���� i,j�� ����
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
			{  // ���� �ε�ġ�� ���� ��Ȳ���� i,j�� ����
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

	printf("�߸��� ���� �ԷµǾ����ϴ�.\n");
	return 0;
}

int InputArray(void)
{
	printf("n �簢 ��� : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

int InputIJ(void)
{
	printf("r�� c�� : ");
	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void Print(int n, int r, int c, long long nAnswer)
{
	printf("%d*%d �簢 ����� %d�� %d�� : %lld\n", n, n, r, c, nAnswer);
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