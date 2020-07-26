#include "stdafx.h"

int InputNum(bool i);
char* InputWord(int len);
void Print(char** arr, int len);
void MemError(void* arr);

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int nNum = InputNum(0);
	int nLong = InputNum(1);

	char **pWord = (char**)malloc(sizeof(char*)*nNum);
	for (int i = 0; i < nNum; i++)
	{
		pWord[i] = InputWord(nLong);
	}
	
	Print(pWord, nNum);

	for (int i = 0; i < nNum; i++)
	{
		free(pWord[i]);
	}
	free(pWord);

	_CrtDumpMemoryLeaks();

	return 0;
}
int InputNum(bool i = false)	// false면 문자개수, true면 최대길이0
{
	if(!i)
		printf("입력할 문자의 개수를 결정해주세요 : ");
	else
		printf("입력할 문자의 최대 길이를 결정해주세요 : ");
	
	int num;
	scanf_s("%d%*c", &num);
	
	return num;
}

char* InputWord(int len)
{
	printf("입력 : ");
	char *word = (char*)calloc((len + 1),sizeof(char));
	if (word == NULL)
		MemError(word);

	char tmp[128] = { 0 };

	fgets(tmp, 128, stdin);

	memcpy(word, tmp, len);
	
	if(strlen(tmp) < len)
		word[strlen(tmp)-1] = '\0';

	return word;
}

void Print(char** arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);
	}
}

void MemError(void* arr)
{
	printf("메모리 할당에 실패했습니다.\n");
	free(arr);
	exit(1);
}

