#include "stdafx.h"
#include <windows.h>

int main(void)
{
	//_tsystem(L"cls");  // 화면을 클리어해주는 명령어
	//_kbhit();  // 키 입력을 감지하여 0또는 1을 반환하는 명령어
	//getch();  // 키 입력을 감지하여 아스키코드를 반환하는 명령어.
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
			nEndCheck = getch();  //버퍼 삭제용
		}
		
	}

	return 0;
}
