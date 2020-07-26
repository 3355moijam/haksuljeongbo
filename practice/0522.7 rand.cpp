#include "stdafx.h"
#include <time.h>

int main(int argc, char* argv[])
{
	int i = 0;
	srand((unsigned)time(NULL));
	//srand(1);	// 시드값이 고정이면 랜덤값도 순서가 고정
	// 수학적 확률과는 다르게 일정횟수 가챠가 진행되면 반드시 한번이 나오게 프로그래밍 해줘야 한다.
	// 박스가챠처럼 해줘야함.
	for (i = 0; i < 10; i++)
		printf("%6d\n", rand());

	for (i = 0; i < 10; i++)
		printf("%6d\n", rand() % 10);

	return 0;
}