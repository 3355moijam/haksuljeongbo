#include "stdafx.h"

int main(void)
{
	int no = 0;

	printf("숫자 세 개를 입력해주세요 : ");

	int num1 = 0, num2 = 0, num3 = 0;

	scanf("%d%d%d", &num1, &num2, &num3);

	printf("no.%d	%d\n", ++no, num1);
	printf("no.%d	%d\n", ++no, num2);
	printf("no.%d	%d\n", ++no, num3);



	return 0;
}
