#include "stdafx.h"

int main(void)
{
	int nInput, nTotal;

	nTotal = 0;
	printf("ù ��° ������ �Է� �� �ּ��� : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("�� ��° ������ �Է� �� �ּ��� : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("�� ��° ������ �Է� �� �ּ��� : ");
	scanf("%d", &nInput);
	nTotal += nInput;

	printf("Total : %d\n", nTotal);

	return 0;
}
