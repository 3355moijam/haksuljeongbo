#include "stdafx.h"

int main(void)
{
	int nInput = 0;
	scanf("%d", &nInput);

	if (nInput > 10) // ���������� �Ǵ�
	{
		int nInput = 20; // ��������1
		printf("%d print1\n", nInput);

		if (nInput < 20) // ��������1�� �Ǵ�
		{
			int nInput = 30; // ��������2
			printf("%d print2\n", nInput);
		}
	}
	printf("%d print3\n", nInput);

	return 0;
}
