#include "stdafx.h"

void PrintString(const char *pszParam)
{
	// �Լ��� ������� ���ڷ� �Է¹����� �� ���� �Լ� ���ο��� ������� ����.
	puts(pszParam);
}

int main(int argc, char* argv[])
{
	
	/*char szBuffer[32] = { "I am a boy" };

	PrintString(szBuffer);
	PrintString("You are a girl");*/

	int nData = 10;
	int test = 0;

	const int *pnData = &nData;
	// *pnData = 20  // error
	// const int* �̰� ����Ű�� ����� ���� �ٲ��� ����.
	pnData = &test;
	printf("%d\n", *pnData);
	test = 10;	// *pnData�� ���ٲ����� test�� ���氡��.
	printf("%d\n", *pnData);

	int* const pnNewData = &nData;
	// pnNewData = NULL  // error
	// int* const �̰� ����Ű�� ����� �ٲ��� ����
	*pnNewData = 30;
	printf("%d %x %x\n", *pnNewData, pnNewData, &nData);
	return 0;
}