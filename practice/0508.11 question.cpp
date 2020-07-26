#include "stdafx.h"

int main(void)
{
	//Q. 수명을 100년으로 가정. 담배 한 개피에 수명 2분씩 단축. 
	//성인(20살)이 된 후 담배를 20년간 하루에 X개피(입력값)를 피웠다면 수명은 얼마나 단축되었고, 몇 살까지 살 수 있을 지 계산하시오.

	int smoke = 0; // 담배 개수
	printf("당신은 하루에 몇개피의 담배를 핍니까? (단위:개피) : ");
	scanf("%d", &smoke);

	// 20년은 365 * 20일
	int discount = smoke * 2 * 365 * 20; // 줄어든 수명(단위 분)
	int lifetime = 100 * 365 * 24 * 60; // 수명(단위 분)
	lifetime -= discount; // 남은 수명(단위 분)

	printf("당신의 수명은 %d년 %d일 %d시간 %d분 단축되었습니다.\n", discount / 60 / 24 / 365, discount / 60 / 24 % 365, discount / 60 % 24, discount % 60);
	printf("그리고 당신은 %d살 %d일 %d시간 %d분 살 수 있습니다.\n", lifetime / 60 / 24 / 365, lifetime / 60 / 24 % 365, lifetime / 60 % 24, lifetime % 60);


	return 0;
}
