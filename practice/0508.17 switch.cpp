#include "stdafx.h"

int main(void)
{
	// ����ġ���� default�� �ƹ� �͵� ������ ���������� ���ִ°� ����. break �־.

	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;

	printf("�������� �� ��Ģ������ �־��ּ���. : ");
	scanf("%d%c%d", &x, &cOperator, &y);

	switch (cOperator)
	{
	case '+':
		nResult = x + y;
		break;

	case '-':
		nResult = x - y;
		break;

	case '*':
		nResult = x * y;
		break;

	case '/':
		nResult = x / y;
		break;

	default:
		puts("ERROR: �� �� ���� ��� �����Դϴ�.");
		break;
	}

	printf("Result: %d\n", nResult);


	return 0;
}
