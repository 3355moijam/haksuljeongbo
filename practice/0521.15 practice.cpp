#include "stdafx.h"

char* InputText(void);
void MemError(void* arr);

int main(int argc, char* argv[])
{

	char *text = InputText();
	int i = 0, index = 0;
	char *cpyText = (char*)calloc(_msize(text), sizeof(char));

	while (text[i] != '\0')
	{
		if (!iswalpha(text[i]))
		{	
			i++;
			continue;
		}
		cpyText[index] = text[i];
		index++;
		i++;
	}
	printf("%s\n", cpyText);

	if(text != NULL)
		free(text);
	if(cpyText != NULL)
		free(cpyText);

	return 0;
}

char* InputText(void)
{
	printf("���ڸ� �Է����ּ��� : ");

	char *string = (char*)calloc(128, sizeof(char));
	if (string == NULL) MemError(string);

	gets_s(string, 128);

	return string;
}

void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}