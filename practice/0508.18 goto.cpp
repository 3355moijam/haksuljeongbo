#include "stdafx.h"

int main(void)
{
	// goto�� ���� ����� ���� ���� �м��� ���� �̰ɷ� ���� ���״� ã�⵵ ����ϱ� ���⼭�� ���� �ؾ���� ��.

	int nInput;

INPUT:
	printf("Input number : ");
	scanf("%d", &nInput);

	if (nInput < 0 || nInput > 10)
		goto INPUT;

	puts("End");

	return 0;
}
