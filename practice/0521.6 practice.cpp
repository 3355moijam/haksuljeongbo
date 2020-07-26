#include "stdafx.h"
//
//char* InputWord(void);
//int GetLength(char* word);
//void Print(int i);
//void MemError(void* arr);
//
//int main(int argc, char* argv[])
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
//	char* input = InputWord();
//	Print(GetLength(input));
//	free(input);
//	_CrtDumpMemoryLeaks();
//
//	return 0;
//}
//char* InputWord(void)
//{
//	printf("입력 : ");
//	char* word = NULL;
//
//	word = (char*)malloc(128);
//	if (word == NULL)
//		MemError(word);
//
//	gets_s(word, 128);
//
//	return word;
//}
//
//int GetLength(char* word)
//{
//	int count = 0;
//	while (word[count] != '\0')
//	{
//		count++;
//
//	}
//
//	return count;
//
//}
//
//void Print(int i)
//{
//	printf("%d\n", i);
//}
//
//void MemError(void* arr)
//{
//	printf("메모리 할당에 실패했습니다.\n");
//	free(arr);
//	exit(1);
//}
