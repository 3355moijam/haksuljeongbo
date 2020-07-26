#include "stdafx.h"

int main(void)
{
	int nInput, nTotal;

	nTotal = 0;
	printf("첫 번째 변수를 입력 해 주세요 : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("두 번째 변수를 입력 해 주세요 : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("세 번째 변수를 입력 해 주세요 : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("Total : %d\n", nTotal);

	return 0;
}
