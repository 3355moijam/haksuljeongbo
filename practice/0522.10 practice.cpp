#include "stdafx.h"
#include <ctype.h>

char* InputWord(void);
int WordCounter(char* sentence, int** target);
int scan(int** target, char alpha);

void lower(char* ch);
void BubSort(int **arr, int count);
void Swap(int *a, int *b);
void MemError(void *arr);
void DoubleFree(void **arr, int len);


int main(int argc, char* argv[])
{
	// �ܾ �Է¹��� ��, ���ĺ� ���� ����
	// �������� ���� ���ĺ��� ����
	// �������� ����
	// ��ҹ��� ����

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	char *szInput = InputWord();
	
	int **wCount = (int**)calloc(26, sizeof(int*));
	if (wCount == NULL) MemError(wCount);
	
	lower(szInput);

	int alphaNum = WordCounter(szInput, wCount);

	BubSort(wCount, alphaNum);

	for (int i = 0; i < alphaNum; i++)
	{
		printf("%c : %d\n", wCount[i][0], wCount[i][1]);
	}

	free(szInput);
	DoubleFree((void**)wCount, alphaNum);

	//_CrtDumpMemoryLeaks();

	return 0;
}


int WordCounter(char* sentence, int** target)
{
	int i = 0, index = 0;
	int alphaNum = 0;
	while (sentence[i] != '\0')
	{
		if (isalpha(sentence[i]))
		{
			index = scan(target, sentence[i]);
			if ( index == -1)	// ���ĺ��� �� ������ ���� ��� ����
			{
				target[alphaNum] = (int*)malloc(sizeof(int) * 2);
				target[alphaNum][0] = sentence[i];
				target[alphaNum][1] = 1;
				alphaNum++;
			}
			else	// ������� count+1
			{
				target[index][1] += 1;
			}
		}
		i++;
	}

	return alphaNum;	//�ܾ� ���� ��ȯ
}

int scan(int** target, char alpha)	// ���ĺ��� �ִ� �ε����� ��ȯ, -1�� ���� ��.
{
	for (int i = 0; i < 26; i++)
	{
		if (target[i] != NULL)
		{
			if (target[i][0] == alpha)
				return i;
		}
		else
			break;
	}
	return -1;
}

void lower(char* ch)
{
	for (int i = 0; i < strlen(ch); i++)
	{
		ch[i] = tolower(ch[i]);
	}
}
char* InputWord(void)
{
	printf("�Է� : ");
	char *word = (char*)calloc(128, sizeof(char));
	if (word == NULL)
		MemError(word);

	gets_s(word, 128);

	return word;
}
void BubSort(int **arr, int count)	//��������
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j][0] > arr[j + 1][0])
			{
				Swap(arr[j]+0, arr[j + 1]+0);
				Swap(arr[j]+1, arr[j + 1]+1);
			}
		}
	}
}
void MemError(void *arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
 }
void DoubleFree(void **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != NULL)
			free(arr[i]);
	}
	free(arr);
}