#include "stdafx.h"
#include <Windows.h>


char* InputWord(void);
int Scroll(char *hello);
void MemError(void);

int main(void)
{
	int check;
	while (1)
	{
		check = Scroll(InputWord());
		
		if (check == 96)	// `�� ������ ����
			break;
	}

	return 0;
}

int Scroll(char *hello)
{
	char *pszHello = (char*)malloc(strlen(hello)+3);
	if (pszHello == NULL)
		MemError();

	sprintf(pszHello, "%s%s", hello, "  ");
	
	char tmp = 'A';
	while (!_kbhit())
	{
		system("cls");
		printf("%s\n", pszHello);
		printf("`�� ������ ����.\n");


		tmp = pszHello[0];
		sprintf(pszHello, "%s%c", pszHello+1, tmp);

		Sleep(50);

	}
	system("cls");
	free(pszHello);

	return getch();
}
char* InputWord(void)
{
	printf("�޽����� �Է����ּ��� : ");
	char temp[128];
	gets_s(temp, 128);
	char *text = (char*)malloc(strlen(temp));

	if (text == NULL)
		MemError();

	printf("%d\n", strlen(temp));

	sprintf(text, "%s", temp);

	return text;
}

void MemError(void)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	exit(1);
}