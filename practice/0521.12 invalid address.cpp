#include "stdafx.h"
//
int* TestFunc(void)
{
	int nData = 10;
	return &nData; // �ڵ尡 ª�Ƽ� ���ƴ� ���µ����������� �ּҴ� ���ư������Ƿ� �ùٸ��� ���� ���.
}

int main(int argc, char* argv[])
{


	int *pnResult = NULL;
	pnResult = TestFunc();

	printf("%d\n", *pnResult);


	return 0;
}
