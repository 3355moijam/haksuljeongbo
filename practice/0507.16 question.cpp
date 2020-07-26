#include "stdafx.h"

int main(void)
{
	printf("몇초는 얼마일까? : ");
	int input;
	scanf("%d", &input);

	printf("%d초는 %02d시간 %02d분 %02d초 입니다.\n", input, input / 3600, input % 3600 / 60, input % 60); 
	// 연산을 변수로 따로 빼면 가독성이 좋아지고, printf에 넣으면 속도가 더 빨라진다.

	
	return 0;
}
