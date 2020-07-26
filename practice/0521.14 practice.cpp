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
			printf("%c�� ���ĺ��� �ƴմϴ�.\n", text[i]);
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