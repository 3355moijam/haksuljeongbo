#include "stdafx.h"

char* InputText(void);
void MemError(void* arr);

int main(int argc, char* argv[])
{
	
	char *text = InputText();
	int i = 0;
	bool check = 0;

	while (text[i] != '\0')
	{
		if (!iswalpha(text[i]))
		{
			printf("%c는 알파벳이 아닙니다.\n", text[i]);
			check++;
			break;
		}
		
		i++;
	}

	if (!check)
	{
		printf("%s\n", text);
	}
	if(text != NULL)
		free(text);

	return 0;
}

char* InputText(void)
{
	printf("문자를 입력해주세요 : ");
	
	char *string = (char*)calloc(128, sizeof(char));
	if (string == NULL) MemError(string);

	gets_s(string, 128);

	return string;
}

void MemError(void* arr)
{
	printf("메모리 할당에 실패했습니다.\n");
	free(arr);
	exit(1);
}