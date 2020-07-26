#include "stdafx.h"

int main(void)
{
	// 스위치문의 default는 아무 것도 없더라도 습관적으로 써주는게 좋다. break 넣어서.

	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;

	printf("이항으로 된 사칙연산을 넣어주세요. : ");
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
		puts("ERROR: 알 수 없는 산술 연산입니다.");
		break;
	}

	printf("Result: %d\n", nResult);


	return 0;
}
