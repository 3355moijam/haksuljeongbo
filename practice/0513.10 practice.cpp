#include "stdafx.h"

int main(void)
{
	printf("정수를 입력해 주세요 : ");
	int nInput;
	scanf_s("%d", &nInput);

	for (int i = 0; i < nInput; i++)
	{
		for (int j = 0; j < nInput; j++)
		{
			if (i == j || i == (nInput-1) - j)
				printf("*");

			else
				printf("_");
		}
		
		printf("\n");
	}

	return 0;
}