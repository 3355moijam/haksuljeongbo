#include "stdafx.h"

int main(void)
{
	printf("������ �Է��� �ּ���. 0�� ������ �����ϴ�: ");
	int nInput = 1, sum = 0;
	 
	
	while (nInput != 0)
	{
		scanf("%d", &nInput);
		sum += nInput;
	}

	printf("%d\n", sum);


	return 0;
}
