#include "stdafx.h"

int main(void)
{
	int nInput = 0;
	scanf("%d", &nInput);

	if (nInput > 10) // 전역변수로 판단
	{
		int nInput = 20; // 지역변수1
		printf("%d print1\n", nInput);

		if (nInput < 20) // 지역변수1로 판단
		{
			int nInput = 30; // 지역변수2
			printf("%d print2\n", nInput);
		}
	}
	printf("%d print3\n", nInput);

	return 0;
}
