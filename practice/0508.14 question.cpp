#include "stdafx.h"

int main(void)
{
	int a, b;
	printf("���� �ٸ� �� ���� �Է� �� �ּ���. : ");
	scanf("%d%d", &a, &b);

	if (a > b)
	{
		printf("%d\n", a - b);
	}
	else if (a < b)
		printf("%d\n", b - a);
	else
		printf("���� �ٸ� ���� �Է� �� �ּ���.\n");


	return 0;
}
