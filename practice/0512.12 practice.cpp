#include "stdafx.h"

int main(void)
{
	printf("구구단 몇단? : ");
	int input = 0;
	scanf_s("%d", &input);
	

	if (input >= 2 && input <= 9)
	{
		for (int i = 1; i <= 9; i++)
			printf("%d * %d = %2d\n", input, i, input * i);
	}

	else
		printf("ERROR\n");


	return 0;
}
