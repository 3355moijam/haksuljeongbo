#include "stdafx.h"

int main(void)
{
	printf("1~9 사이의 정수를 입력해주세요: ");
	int num = 0;
	scanf("%d", &num);

	if (num < 1)
		num = 1;
	else if (num > 9)
		num = 9;

	int i = 0;
	while (i < num)
	{
		printf("*");
		i++;
	}
	printf("\n");

	return 0;
}
