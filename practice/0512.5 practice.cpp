#include "stdafx.h"

int main(void)
{
	printf("정수를 입력해 주세요. 0을 넣으면 끝납니다: ");
	int nInput = 1, sum = 0;
	 
	
	while (nInput != 0)
	{
		scanf("%d", &nInput);
		sum += nInput;
	}

	printf("%d\n", sum);


	return 0;
}
