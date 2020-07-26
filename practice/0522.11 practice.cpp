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
	// 숫자 입력받아 그 수만큼 단어를 입력받은 뒤, 오름차순
	// 오름차순 정렬
	// 대소문자 무시
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int count = InputNum(false);
	int nStrLeng = InputNum(true);

	char **pStrArr = (char**)calloc(count, sizeof(char*));
	if (pStrArr == NULL)
		MemError(pStrArr);

	// n개의 입력을 받는 단계
	for (int i = 0; i < count; i++) 
	{
		pStrArr[i] = InputWord(nStrLeng);

		if (*pStrArr[i] == '\0')	// 그냥 엔터치면 넘어감
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
	printf("입력 : ");
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

int InputNum(bool i = false)    // false면 문자개수, true면 최대길이
{
	if (!i)
		printf("입력할 문자의 개수를 결정해주세요 : ");
	else
		printf("입력할 문자의 최대 길이를 결정해주세요 : ");

	int num;
	scanf_s("%d%*c", &num);

	return num;
}

void BubSort(char **arr, int count)	//오름차순
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
	printf("메모리 할당에 실패했습니다.\n");
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