#include "stdafx.h"


int main(int argc, char* argv[])
{
	
	wchar_t *pwszData = L"String";
	/*wchar_t wszData[32];

	wcscpy(wszData, pwszData);
	wprintf(L"%s\n", wszData);*/

	char szData[32];
	size_t nConverted = 0;

	nConverted = wcstombs(NULL, pwszData, 32); // �޴� ���� NULL�� ������ wchar_t�� char�� �ٲٱ� ���� �ʿ��� �޸� ���� ��ȯ�Ѵ�.
	printf("%d\n", nConverted);

	nConverted = wcstombs(szData, pwszData, 32);
	printf("%s (%d)\n", szData, nConverted);


	return 0;
}