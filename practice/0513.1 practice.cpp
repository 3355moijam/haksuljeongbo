#include "stdafx.h"

int main(void)
{
	int A = 0, Z = 0, input, ZA = 0;
	printf("0~99 ���� �Է� : ");
	scanf_s("%d", &input);
	//////////////////////////////////

	for (int i = 0; i < input; i++)
	{
		A = i / 10;
		Z = i % 10;
		ZA = Z * 10 + A;
		if(i + ZA == input)
			printf("%02d %02d\n\n", i, ZA);
	}
	
	return 0;
}
