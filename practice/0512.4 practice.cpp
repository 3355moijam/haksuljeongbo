#include "stdafx.h"

int main(void)
{
	printf("���� ������ �Է��� �ּ���: ");
	int nInput = 0;
	scanf("%d", &nInput);

	if (nInput < 1)
	{
		printf("���� ������ �Է��� �ּ���");
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
