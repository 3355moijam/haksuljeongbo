// practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(void)
{

	printf("%d\n", 1234);
	printf("%d, %d\n", 1234, -5678);
	printf("%+d, %+d\n", 1234, -5678); // 부호붙여서 출력

	printf("%8d\n", 1234); // 8자리 정수로 맞추고 오른쪽정렬
	printf("%08d\n", 1234); // 8자리 정수로 맞추되 빈자리는 0으로 채우기
	printf("%-08d\n", 1234);  // 8자리 정수로 맞추고 왼쪽정렬

	return 0;
}

