#include "stdafx.h"


int main(int argc, char* argv[])
{
	
	wchar_t *pwszData = L"String";
	/*wchar_t wszData[32];

	wcscpy(wszData, pwszData);
	wprintf(L"%s\n", wszData);*/

	char szData[32];
	size_t nConverted = 0;

	nConverted = wcstombs(NULL, pwszData, 32); // 받는 곳에 NULL을 넣으면 wchar_t를 char로 바꾸기 위해 필요한 메모리 수를 반환한다.
	printf("%d\n", nConverted);

	nConverted = wcstombs(szData, pwszData, 32);
	printf("%s (%d)\n", szData, nConverted);


	return 0;
}