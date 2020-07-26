#include "stdafx.h"

int main(void)
{
	printf("양의 정수를 입력해 주세요: ");
	int nInput = 0;
	scanf("%d", &nInput);

	if (nInput < 1)
	{
		printf("양의 정수를 입력해 주세요");
		nInput = 0;
	}

	int i = 1;
	while (i <= nInput) 
	{	
		printf("%d ", 3 * i);
		i++;
	}
	printf("\n");

	return 0;
}
