#include "stdafx.h"

int main(void)
{
	// goto는 버그 만들기 아주 좋고 분석도 힘들어서 이걸로 생긴 버그는 찾기도 힘드니까 여기서만 쓰고 잊어버릴 것.

	int nInput;

INPUT:
	printf("Input number : ");
	scanf("%d", &nInput);

	if (nInput < 0 || nInput > 10)
		goto INPUT;

	puts("End");

	return 0;
}
