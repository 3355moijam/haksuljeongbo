#include "stdafx.h"

int main(void)
{
	// 토너먼트 방식의 최대 최소값을 구하는 방법

	//int nMax = 0, nMin = 0;
	//int a, b, c;
	//scanf("%d%d%d", &a, &b, &c);
	//nMax = a > b ? a : b;
	//nMax = nMax > c ? nMax : c;
	//nMin = a < b ? a : b;
	//nMin = nMin < c ? nMin : c;

	//printf("최대: %d\n최소: %d\n", nMax, nMin);
	/////////////////////////////////////////////////

	
	//// 서바이벌 방식의 최대, 최소값을 구하는 방법	
	//int nMax = 0, nMin = 0, nInput = 0;

	//printf("숫자를 세 번 입력하세요\n");
	//scanf("%d", &nInput);
	//nMax = nInput;
	//nMin = nInput;
	//scanf("%d", &nInput);
	//nMax = nInput > nMax ? nInput : nMax;
	//nMin = nInput < nMin ? nInput : nMin;
	//scanf("%d", &nInput);
	//nMax = nInput > nMax ? nInput : nMax;
	//nMin = nInput < nMin ? nInput : nMin;
	//printf("최대 : %d\n최소 : %d\n", nMax, nMin);
	/////////////////////////////////////////////////


	//question
	int nMax = -100, nInput = 0;
	
	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("MAX : %d\n", nMax);




	return 0;
}
