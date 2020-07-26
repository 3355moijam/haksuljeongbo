#include "stdafx.h"

int main(void)
{
	// 포인터 배열. 포인터가 들어있는 배열
	int a = 10, b = 20, c = 30;
	int *pA[3] = { NULL, NULL, NULL };

	//배열포인터. 배열을 포인터로 가져다 쓰는 것
	int arr[2][3] = { 10,20,30,40,50,60 };
	int(*pArr)[3] = NULL;
	
	pA[0] = &a;
	pA[1] = &b;
	pA[2] = &c;

	printf("%x %x %x\n", &a, &b, &c);
	printf("%x %x %x\n", pA[0], pA[1], pA[2]);
	printf("%x %x %x\n", *(pA + 0), *(pA + 1), *(pA + 2));


	printf("%x %x %x\n", *&a, *&b, *&c);
	printf("%x %x %x\n", *pA[0], *pA[1], *pA[2]);
	printf("%x %x %x\n", **(pA + 0), **(pA + 1), **(pA + 2));


	pArr = arr;
	printf("%d %d %d\n", pArr[0][0], pArr[0][1], pArr[0][2]);
	printf("%d %d %d\n", pArr[1][0], pArr[1][1], pArr[1][2]);

	return 0;
}
