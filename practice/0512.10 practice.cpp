#include "stdafx.h"

int main(void)
{
	printf("�� ������ �Է��� �ּ���: ");
	int input1, input2, sum = 0;
	scanf("%d%d", &input1, &input2);

	//swap
	if (input1 > input2)
	{
		int temp = input1;
		input1 = input2;
		input2 = temp;
	}


	// for
	for (int i = input1; i <= input2; i++)
	{
		sum += i;
	}
	printf("for : %d\n", sum);
	///////////////

	// while
	sum = 0;
	int k = input1;
	while (k <= input2)
	{
		sum += k;
		k++;
	}
	printf("while : %d\n", sum);
	//////////////
	return 0;
}
