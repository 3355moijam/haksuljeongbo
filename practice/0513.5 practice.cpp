#include "stdafx.h"
#include <windows.h>

int main(void)
{
	//_tsystem(L"cls");  // ȭ���� Ŭ�������ִ� ��ɾ�
	//_kbhit();  // Ű �Է��� �����Ͽ� 0�Ǵ� 1�� ��ȯ�ϴ� ��ɾ�
	//getch();  // Ű �Է��� �����Ͽ� �ƽ�Ű�ڵ带 ��ȯ�ϴ� ��ɾ�.
	char szHello[8] = { "Hello  " };
	printf("%s\n", szHello);
	char cTemp = 'A';
	int nEndCheck = 0;
	
	while (1)
	{
		if (nEndCheck == 13)
			break;

		if (_kbhit())
		{
			cTemp = szHello[0];
			for (int i = 0; i < 7; i++)
			{
				szHello[i] = szHello[i + 1];
			}
			szHello[6] = cTemp;

			//_tsystem(L"cls");
			system("cls");
			printf("%s\n", szHello);
			nEndCheck = getch();  //���� ������
		}
		
	}

	return 0;
}
