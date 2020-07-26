#include "stdafx.h"
#include <ctype.h>

char* InputWord(int len);
int InputNum(bool i);

void lower(char* ch);
void BubSort(char **arr, int count);
void Swap(char **arr, int b);
void MemError(void *arr);
void DoubleFree(char **arr, int len);
void Print(char **arr, int len);


int main(int argc, char* argv[])
{
	// ���� �Է¹޾� �� ����ŭ �ܾ �Է¹��� ��, ��������
	// �������� ����
	// ��ҹ��� ����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int count = InputNum(false);
	int nStrLeng = InputNum(true);

	char **pStrArr = (char**)calloc(count, sizeof(char*));
	if (pStrArr == NULL)
		MemError(pStrArr);

	// n���� �Է��� �޴� �ܰ�
	for (int i = 0; i < count; i++) 
	{
		pStrArr[i] = InputWord(nStrLeng);

		if (*pStrArr[i] == '\0')	// �׳� ����ġ�� �Ѿ
		{
			count = i;
			free(pStrArr[i]);
			break;
		}
		lower(pStrArr[i]);
	}
	//////

	BubSort(pStrArr, count);

	Print(pStrArr, count);

	DoubleFree(pStrArr, count);

	_CrtDumpMemoryLeaks();

	return 0;
}

void lower(char* ch)
{
	for (int i = 0; i < strlen(ch); i++)
	{
		ch[i] = tolower(ch[i]);
	}
}

char* InputWord(int len)
{
	printf("�Է� : ");
	char *word = (char*)calloc((len+1), sizeof(char));
	if (word == NULL)
		MemError(word);

	char tmp[128] = { 0 };
	fgets(tmp, 128, stdin);

	memcpy(word, tmp, len);

	if (strlen(tmp) < len)
		word[strlen(tmp) - 1] = '\0';

	return word;
}

int InputNum(bool i = false)    // false�� ���ڰ���, true�� �ִ����
{
	if (!i)
		printf("�Է��� ������ ������ �������ּ��� : ");
	else
		printf("�Է��� ������ �ִ� ���̸� �������ּ��� : ");

	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void BubSort(char **arr, int count)	//��������
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				Swap(arr, j);
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
void Swap(char **arr, int j)
{
	char *tmp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = tmp;
}

void strSwap(char *a, char *b)
{
	strcpy(char tmp, )//
}
void DoubleFree(char **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != NULL)
			free(arr[i]);
	}
	free(arr);
}

void Print(char **arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s ", arr[i]);
	}
}