#include "stdafx.h"

int main(void)
{
	printf("몇 개의 정수를 입력할 건가요? : ");
	int count = 0;
	float nInput = 0, sum = 0, avg = 0;
	
	scanf_s("%d", &count);
	printf("입력해주세요 : ");


	int i = 0;
	while (i < count)
	{
		scanf_s("%f", &nInput);
		sum += nInput;
		i++;
	}

	if(count != 0)
		avg = sum / count;
	
	printf("%.2f\n", avg);

	return 0;
}
