#include "stdafx.h"

int main(void)
{
	printf("당신의 키는 몇cm입니까 용자여 : ");

	int height = 0;

	scanf("%d", &height);

	printf("%s\n", height >= 150 ? "합격" : "불합격");

	return 0;
}
