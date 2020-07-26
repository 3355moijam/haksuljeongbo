#include "stdafx.h"

void PrintString(const char *pszParam)
{
	// 함수가 상수형을 인자로 입력받으면 이 값은 함수 내부에서 변경되지 않음.
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
	// const int* 이건 가리키는 대상의 값을 바꾸지 못함.
	pnData = &test;
	printf("%d\n", *pnData);
	test = 10;	// *pnData는 못바꾸지만 test는 변경가능.
	printf("%d\n", *pnData);

	int* const pnNewData = &nData;
	// pnNewData = NULL  // error
	// int* const 이건 가리키는 대상을 바꾸지 못함
	*pnNewData = 30;
	printf("%d %x %x\n", *pnNewData, pnNewData, &nData);
	return 0;
}