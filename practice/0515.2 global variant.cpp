#include "stdafx.h"

int g_nCounter = 0;
void InitCounter(int nData);
void IncreaseCounter(void);

int main(void)
{
	// 전역변수
	// include 아래에 함수선언하듯이 똑같이 변수 선언해주면 된다.
	// 이 cpp 말고 다른 cpp에서 사용도 가능. extern int variant;로 가져올 수 있음
	// 전역변수와 지역변수 이름이 같다면 지역변수가 우선. 전역변수를 쓸땐 ::variant 식으로 사용.
	// 전역변수는 관습적으로 이름 앞에 g_를 붙여준다(global이란 뜻)

	InitCounter(10);

	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);

	return 0;
}

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter(void)
{
	g_nCounter++;
}