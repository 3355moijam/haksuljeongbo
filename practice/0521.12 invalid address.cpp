#include "stdafx.h"
//
int* TestFunc(void)
{
	int nData = 10;
	return &nData; // 코드가 짧아서 돌아는 가는데지역변수의 주소는 날아가버리므로 올바르지 않은 방법.
}

int main(int argc, char* argv[])
{


	int *pnResult = NULL;
	pnResult = TestFunc();

	printf("%d\n", *pnResult);


	return 0;
}
