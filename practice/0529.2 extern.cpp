#include "stdafx.h"

// 외부 함수 선언
void InitCounter(int i);
void IncreaseCounter();

// 외부 전역변수 선언. 정의가 아님. source에 있다
extern int g_nCounter;

int main(int argc, char* argv[])
{
	

	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);



	return 0;
}