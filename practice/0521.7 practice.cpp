#include "stdafx.h"

char* InputWord();
char* ReverseStr(char* word);
int GetLength(char* word);
void MemError(void* arr);

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	
	// �Լ� ������ �Ҵ��� �޸𸮴� ���ο��� �����ϴ��� �����ͼ� �ܺο��� �����Ѵ�.
	char *szInput = ReverseStr(InputWord());

	printf("%s\n", szInput);

	free(szInput);

	_CrtDumpMemoryLeaks();

	return 0;
}

char* InputWord()
{
	printf("�Է� : ");
	char input[128] = { 0 };
	
	gets_s(input, 128);

	char *word = (char*)malloc(GetLength(input) + 1);
	if (word == NULL)
		MemError(word);
	
	memcpy(word, input, GetLength(input) + 1);

	return word;
}

char* ReverseStr(char* word)
{
	int len = GetLength(word), i = 0;
	char* rWord = (char*)malloc(sizeof(char)*(len + 1));
	if (rWord == NULL)
		MemError(rWord);

	for (i = 0; i < len; i++)
	{
		rWord[i] = word[(len - 1) - i];
	}
	rWord[i] = '\0';
	free(word);

	return rWord;
}

int GetLength(char* word)
{
	int count = 0;
	while (word[count] != '\0')
	{
		count++;
	}

	return count;
}


void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}